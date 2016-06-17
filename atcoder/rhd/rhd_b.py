n = int(input())
p = [list(map(int,input().split())) for i in range(n)]

ans = 'W'
x = p[0][0]

class End(Exception):
    pass

try:
    for i in range(1,n-1):
        if p[i][0] - p[i][1] > x:
            ans += 'W'
            x = p[i][0]
        elif p[i][0] + p[i][1] < p[i+1][0]:
            ans += 'E'
            x = p[i][0] + p[i][1]
        else:
            raise End
    else:
        print(ans + 'E')
except End:
    print("IMPOSSIBLE")

