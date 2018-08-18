s = str(input())
n = int(input())


one = 0
ret = 0
for i in range(len(s)):
    if int(s[i]) == 1:
        one += 1
    else:
        ret = int(s[i])
        break

if one >= n:
    print(1)
else:
    print(ret)
