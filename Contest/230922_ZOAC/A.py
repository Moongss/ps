N = int(input())

result = 0
for i in range(N):
    line = input()
    if "01" in line or "OI" in line:
        result += 1

print(result)