from math import ceil

N, K = tuple(map(int, input().split()))

A = list(map(int, input().split()))

l = len(A)

i = A.index(1)
rs = ceil((l - 1 - i)/(K-1))
ls = ceil(i/(K-1))


if (N == K):
    res = 1
elif (((l - i) < K) or (i + 1 < K)):
    res = ceil((l - 1)/(K - 1))
else:
    res = ls + rs


print(res)
