n, x  = input().split()
n = int(n)
t = min(int(x), int(x[::-1]))
ans = 0
if (t < int(x)):
    print(ans)
else:
    for i in range(13):
        f = int(x+'0'*i)
        if f <= n:
            ans += 1
        if (int(x) != int(x[::-1])):
            f = int(x[::-1]+'0'*i)
            if f <= n:
                ans += 1
    print(ans)




