s  = input()
ans = 0
tgt = "atcoder"
for si in tgt:
    idx = s.find(si)
    base = tgt.find(si)
    s = s[:base] + si + s[base:idx] + s[idx+1:]
    # print(s)
    ans += idx - base
print(ans)




