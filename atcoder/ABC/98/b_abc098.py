n = int(input())
s = input()

res = [None] * n

for i in range(n):
    l = s[:i]
    r = s[i:]
    cnt = 0
    chk_s = ""

    for j in range(i):
        if not l[j] in chk_s:
            chk_s += l[j]
            if l[j] in r:
                cnt += 1

    else:
        res[i] = cnt

print(max(res))
