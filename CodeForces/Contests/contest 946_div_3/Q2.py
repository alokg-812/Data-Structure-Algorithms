def decode_string(t, test_cases):
    results = []
    
    for case in test_cases:
        n, b = case
        distinct_chars = sorted(set(b))
        r = ''.join(distinct_chars)
        
        # Create the symmetric mapping
        mapping = {}
        length = len(r)
        for i in range(length):
            mapping[r[i]] = r[length - i - 1]
        
        # Decode the string b
        s = ''.join(mapping[ch] for ch in b)
        results.append(s)
    
    return results

# Reading input
import sys
input = sys.stdin.read
data = input().split()

t = int(data[0])
index = 1
test_cases = []

for _ in range(t):
    n = int(data[index])
    b = data[index + 1]
    test_cases.append((n, b))
    index += 2

# Processing the test cases
decoded_strings = decode_string(t, test_cases)

# Printing the results
for s in decoded_strings:
    print(s)
