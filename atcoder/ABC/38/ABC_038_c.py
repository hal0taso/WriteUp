n = int(input())
a = list(map(int,input().split()))
ans = 0
a.append(0)
tmp=0
for i in range(1,n+1):
    if a[i-1] >= a[i]:
        if i != n+1:
            x=i-tmp
            ans+=x*(x+1)//2
            tmp=i
        else:
            x=i-tmp+1
            ans+=x*(x+1)//2
print(ans)
