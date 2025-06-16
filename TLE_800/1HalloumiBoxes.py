def check(arr, n):
    for i in range(1, n):
        if arr[i] < arr[i - 1]:
            return False
    return True

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    
    if k >= 2 or check(arr, n):
        print("YES")
    else:
        print("NO")
