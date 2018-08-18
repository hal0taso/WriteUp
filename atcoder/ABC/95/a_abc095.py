# -*- coding: utf-8 -*-

order = input()

ret = 700
for i in order:
    if i == 'o':
        ret += 100

print(ret)
