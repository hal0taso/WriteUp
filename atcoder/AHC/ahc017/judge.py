import pandas as pd
import networkx as nx
import sys
sys.setrecursionlimit(10**7) # 再起回数の設定
from pathlib import Path
import argparse
import ipdb
# import fileinput

readsplit = lambda f, _type: list(map(_type, f.readline().rstrip('\n').split()))

# V: 頂点数
# g[v] = {(w, cost)}:
#     頂点vから遷移可能な頂点(w)とそのコスト(cost)
# r: 始点の頂点
 
from heapq import heappush, heappop
INF = 10**9
def dijkstra(N, G, s):
    dist = [INF] * N
    que = [(0, s)]
    dist[s] = 0
    while que:
        c, v = heappop(que)
        if dist[v] < c:
            continue
        for t, cost in G[v]:
            if dist[v] + cost < dist[t]:
                dist[t] = dist[v] + cost
                heappush(que, (dist[t], t))
    return dist

def input_parser(f1):
    n, m, d, k = readsplit(f1, int)
    # G = [set() for i in range(n)]
    edges = [None] * m
    weights = [None] * m
    coord = [None] * n
    for i in range(m):
        u, v, w = readsplit(f1, int)
        u -= 1
        v -= 1
        # print(u, v, w)
        # G[u].add((v, w))
        # G[v].add((u, w))
        # G.add_edge(u, v, weight=w)
        edges[i] = (u, v)
        weights[i] = w
    for i in range(n):
        coord[i] = readsplit(f1, int)
    return n, m, d, k, edges, weights, coord
    

def main(infile: str, outfile: str):
    infile = Path(infile)
    outfile = Path(outfile)
    with open(infile, mode='r') as f1:
        n, m, d, k, edges, weights, coord = input_parser(f1)
    G = [set() for i in range(n)]
    deg = [0 for i in range(n)]
    for i in range(m):
        u, v = edges[i]
        w = weights[i]
        G[u].add((v, w))
        G[v].add((u, w))
        deg[u] += 1
        deg[v] += 1
    f = 0
    for i in range(n):
        dist = dijkstra(n, G, i)
        f += sum([dist[j] for j in range(n) if i != j])
    f /= n*(n-1)
    with open(outfile, mode='r') as f2:
        partition = readsplit(f2, int)
    ret = 0
    # ipdb.set_trace()
    Gk = [[set() for i in range(n)] for day in range(d)]
    for i in range(m):
        u, v = edges[i]
        w = weights[i]
        for day in range(d):
            if day != partition[i]-1:
                Gk[day][u].add((v, w))
                Gk[day][v].add((u, w))
        
    fk = [0 for day in range(d)]
    unreachable_k = [0 for i in range(d)]
    for day in range(d):
        for i in range(n):
            dist = dijkstra(n, Gk[day], i)
            for j in range(n):
                if i != j and dist[j] == INF:
                    unreachable_k[day] += 1
            fk[day] += sum([dist[j] for j in range(n) if i != j])
        unreachable_k[day] //= 2
        fk[day] /= n*(n-1)
        # print(f"{fk[day] - f:.3f}")
    ret = (sum(fk) - f * d)/d
    ret = round(10**3 * ret)

    print(f"{n} {m} {d} {k} {ret} {f:.3f} {max(deg)} " + " ".join([f"{fk[day] - f:.3f}" for day in range(d)]) + " " + " ".join([f"{unreachable_k[day]}" for day in range(d)]))
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Judge AHC output.')
    parser.add_argument('infile', metavar='INPUT', type=str,
                    help='an input file')
    parser.add_argument('outfile', metavar='OUTPUT', type=str,
                    help='an output file')

    args = parser.parse_args()
    # print(args)
    main(args.infile, args.outfile)
    