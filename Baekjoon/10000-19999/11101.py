T = int(input())
for _ in range(T):
    s = input()
    m = dict()
    a = list(s.split(","))

    for _ in range(len(a)):
        m[a[_].split(":")[0]] = a[_].split(":")[1]

    s = input()
    a = list(s.split("|"))

    ret = 42424242
    for _ in range(len(a)):
        _ = a[_].split("&")
        tmp = -1
        for __ in range(len(_)):
            tmp = max(tmp, int(m[_[__]]))
        ret = min(ret, tmp)
    
    print(ret)

