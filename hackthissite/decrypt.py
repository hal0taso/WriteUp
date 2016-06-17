# -*- coding: utf-8 -*-

import sys


f = open(sys.argv[1]).read()
a = f.split('\n')
a_parse = [list[0:-1] for list in a]
a_parse[-1] += '0'

enc = []
ascii_enc = []
# return list length of a_parse
a_length = len(a_parse)
for n in range(a_length):
    enc.extend(list(map(int, a_parse[n].split('.'))))

for n in range(0,len(enc),3):
    ascii_enc.append(enc[n]+enc[n+1]+enc[n+2])

comp = [item - min(ascii_enc) for item in ascii_enc]

mx = max(comp)
mn = min(comp)

for i in range(127 - 111):
    result = [chr(item + i) for item in comp]
    print(''.join(result))
