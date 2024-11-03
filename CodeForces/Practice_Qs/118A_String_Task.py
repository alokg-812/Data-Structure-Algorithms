str = list(input())
n = len(str)
print(str,n)
new_str = str
for i in range(1,n,1):
    if str[i] in 'AEIOUYaeiouy':
        new_str += ''
    else:
        new_str += str[i]
for i in range(1,n,1):
    if(i%2 != 0):
        new_str[i] = '.'
print(new_str)