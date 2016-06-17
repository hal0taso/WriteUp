n, m = map(int, input().split())

ans = set((map(int,input().split())))
num = set([x for x in range(1,m+1)])

diff = list(num.difference(ans))

print(' '.join(map(str,sorted(diff))))
