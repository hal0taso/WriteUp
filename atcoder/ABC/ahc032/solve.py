import os
from pathlib import Path
import time

MOD = 998244352
def calc_score(inbound: Path, outbound: Path):
    with open(inbound, "r") as f:
        data = list(map(int, f.read().strip().split()))
    n, m, k = data[0:3]
    data = data[3:]
    a = [[data[i * n + j] for j in range(n)] for i in range(n)]
    data = data[n * n:]
    s = []
    for _ in range(m):
        si = [[data[i * 3 + j] for j in range(3)] for i in range(3)]
        data = data[9:]
        s.append(si)

    with open(outbound, "r") as f:
        data = list(map(int, f.read().strip().split()))
    l = data[0]
    data = data[1:]
    o = [(data[_], data[_+1], data[_+2]) for _ in range(0, l*3, 3)]

    return calc_score_from_data(n, m, k, a, s, l, o)

def calc_score_from_data(n, m, k, a, s, l, o):
    assert l <= k, "[Error] l > k"

    for i in range(l):
        mi, pi, pj = o[i]
        assert 0 <= mi < m, "[Error] mi < 0 or mi >= m"
        stamp = s[mi]
        for si in range(3):
            for sj in range(3):
                assert 0 <= pi + si < n, "[Error] pi + si < 0 or pi + si >= n"
                assert 0 <= pj + sj < n, "[Error] pj + sj < 0 or pj + sj >= n"
                a[pi + si][pj + sj] = (a[pi + si][pj + sj] + stamp[si][sj]) % MOD

    
    score = 0
    for i in range(n):
        for j in range(n):
            score += a[i][j] % MOD
    return score
            
    

def main():
    inbound = Path("in")
    outbound = Path("out")

    if not outbound.exists():
        outbound.mkdir()

    paths = sorted(list(inbound.glob("*.txt")))

    cmd = 'cd "/Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/ABC/ahc032/" && g++ abc_a.cpp -std=c++20 -O2 -DLOCAL_DEBUG -o abc_a && "/Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/ABC/ahc032/"abc_a'

    score_list = []
    perf_list = []

    for path in paths:
        print(f"Processing {path.name}")
        start = time.perf_counter() 
        os.system(f"{cmd} < {path} > {outbound / path.name}")
        end = time.perf_counter()
        score = calc_score(path, outbound / path.name)
        perf = end - start
        score_list.append(score)
        perf_list.append(perf)
        print(f"{path.name}: {score} {perf}sec")

    print(f"Max: Score:{max(score_list)}, Perf:{max(perf_list)}sec")
    print(f"Min: Score:{min(score_list)}, Perf:{min(perf_list)}sec")
    print(f"Mean: Score{sum(score_list) / len(score_list)}:, Perf:{sum(perf_list) / len(perf_list)}sec")


if __name__ == "__main__":
    main()