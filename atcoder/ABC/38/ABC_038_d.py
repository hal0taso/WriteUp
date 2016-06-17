n = int(input())
box = [list(map(int, input().split())) for i in range(n)]
x0 = sorted(sorted(box,key=lambda x:x[1],reverse=True),key=lambda x:x[0],reverse=True)
x1 = sorted(sorted(box,key=lambda x:x[0],reverse=True),key=lambda x:x[1],reverse=True)
tmp0 = x0[0]
tmp1 = x1[0]
ans = [0,0]
for i in range(1,n):
    if tmp0[0] > x0[i][0] and tmp0[1] > x0[i][1]:
        tmp0 = x0[i]
        ans[0]+=1
    if tmp1[0] > x1[i][0] and tmp1[1] > x1[i][1]:
        tmp1 = x1[i]
        ans[1]+=1
print(max(ans)+1)
