
yyyymmdd = input()

year = int(yyyymmdd[0:4])
month = int(yyyymmdd[5:7])
day = int(yyyymmdd[8:10])

N = int(input())
day += N

if (day > 30):
    month += ((day - 1) // 30)
    day = (day - 1) % 30 + 1

if (month > 12):
    year += ((month - 1) // 12)
    month = (month - 1) % 12 + 1

day = str(day).zfill(2)
month = str(month).zfill(2)


print(f'{year}-{month}-{day}')
