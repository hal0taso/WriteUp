# -*- coding: utf-8 -*-

s = input().split('+')
ans = 0
for i in s:
    if not '0' in i:
        ans += 1
print(ans)
