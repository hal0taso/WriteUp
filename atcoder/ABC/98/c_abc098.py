N = int(input())
S = input().strip()

S = S.rstrip('W')
S = S.lstrip('E')

res = len(S)
for i in range(1, len(S)):
    cnt = S[:i - 1].count('W')
    cnt += S[i:].count('E')
    if cnt < res:
        res = cnt

print(res)
