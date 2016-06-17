n,q = map(int,input().split())

z = list(map(int,input().split()))

query = [list(map(int, input().split())) for i in range(q)]
ans = [None]*q
for i in range(q):
    ans[i] = len(set(z[query[i][0]-1:query[i][1]]))
else:
    print('\n'.join(map(str, ans)))
