# -*- coding: utf-8 -*-
N = int(input())
np = []
for i in range(N):
    np.append(list(map(int, input().split())))

acute, obtuse, right = 0, 0, 0

for i in range(N - 2):
    x1 = np[i][0]
    y1 = np[i][1]
    for k in range(i + 1, N - 1):
        x2 = np[k][0]
        y2 = np[k][1]
        for l in range(k + 1, N):
            x3 = np[l][0]
            y3 = np[l][1]
            r = [(x1 - x2)**2 + (y1 - y2)**2,
                 (x2 - x3)**2 + (y2 - y3)**2,
                 (x1 - x3)**2 + (y1 - y3)**2]
            r.sort()
            c = r[0] + r[1] - r[2]
            if c == 0:
                right += 1
            elif c > 0:
                acute += 1
            else:
                obtuse += 1
print(acute, right, obtuse)
