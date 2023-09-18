S = ["Never gonna give you up", "Never gonna let you down", "Never gonna run around and desert you", "Never gonna make you cry", "Never gonna say goodbye", "Never gonna tell a lie and hurt you", "Never gonna stop"]

flag = False
N = int(input())
for i in range(N):
    tmp = input()
    if tmp not in S:
        flag = True
        break

if flag:
    print("Yes")
else:
    print("No")