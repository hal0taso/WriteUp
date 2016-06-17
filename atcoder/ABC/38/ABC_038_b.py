d=[input().split() for i in range(2)]
print(((d[0][0] in d[1]) or (d[0][1] in d[1])) and 'YES' or 'NO')
