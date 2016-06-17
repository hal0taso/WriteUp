import copy

w,h=list(map(int, input().split()))

img = [input() for i in range(h)]

ans = [list('.'*w) for j in range(h)]

class End(Exception):
    pass

for i in range(h):
    for j in range(w):
        cnt = 0
        for di in range(-1,2):
            for dj in range(-1,2):
                ci, cj = i + di, j + dj
                if ci < 0 or cj < 0 or ci >= h or cj >= w or img[ci][cj] == "#":
                    cnt += 1
        if cnt == 9:
            ans[i][j] = '#'
            
t = copy.deepcopy(ans)
for i in range(h):
    for j in range(w):
        cnt = 0
        try:
            for di in range(-1,2):
                for dj in range(-1,2):
                    ci, cj = i + di, j + dj
                    if ci < 0 or cj < 0 or ci >= h or cj >= w:
                        continue
                    elif ans[ci][cj] == '#':
                        raise End
##                        cnt += 1
#        if cnt >= 1:
        except End:
            t[i][j] = '#'

##try:
##    for i in range(h):
##        for j in range(w):
##            if t[i][j] == img[i][j]:
##                pass
##            else:
##                raise End
##    else:
##        print("possible")
##        for i in range(h):
##            print(''.join(ans[i]))
##except End:
##    print("impossible")

t = [''.join(t[i]) for i in range(h)]
ans = [''.join(ans[i]) for i in range(h)]
if t == img:
    print('possible')
    for i in range(h):
      print(''.join(ans[i]))
else:
    print('impossible')
