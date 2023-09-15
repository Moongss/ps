def print_move_cnt():
    result = 1
    for i in range(N):
        result *= 2
    
    print(result - 1)

def solve(cur, start_point, end_point):
    if cur == N:
        print(f'{start_point} {end_point}')
    else:
        mid_point = 6 - (start_point + end_point)
        
        solve(cur + 1, start_point, mid_point)
        print(f'{start_point} {end_point}')
        solve(cur + 1, mid_point, end_point)


N = int(input())

print_move_cnt()
if N <= 20:
    solve(1, 1, 3)