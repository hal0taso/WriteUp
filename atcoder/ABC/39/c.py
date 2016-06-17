key = "WBWBWWBWBWBWWBWBWWB"
key=key*3
here = input()[0:12]
result = ["Do", "Re", "Mi", "Fa", "So", "La", "Si"]
for n in range(12):
    #print(here)
    #print(key[n:n+12])
    if(key[n:n+12] in here):
        if n <= 4:
            print(result[n//2])
        elif n > 4 :
            print(result[(n-5)//2 + 3])
