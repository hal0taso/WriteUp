# -*- coding: utf-8 -*-

from sys import stdin

n = stdin.readline()
lines = stdin.readlines()
sum = 0
s = []
p = []

for item in lines:
    i = item.split()
    s.append(i[0])
    p.append(int(i[1]))
    sum += int(i[1])

m = max(p)

if sum / 2 < m:
    print(s[p.index(m)])
else:
    print("atcoder")
