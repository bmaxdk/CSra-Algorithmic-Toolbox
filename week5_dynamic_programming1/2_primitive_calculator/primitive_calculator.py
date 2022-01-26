# # Uses python3
# import sys

# def optimal_sequence(n):
#     sequence = []
#     while n >= 1:
#         sequence.append(n)
#         if n % 3 == 0:
#             n = n // 3
#         elif n % 2 == 0:
#             n = n // 2
#         else:
#             n = n - 1
#     return reversed(sequence)

# input = sys.stdin.read()
# n = int(input)
# sequence = list(optimal_sequence(n))
# print(len(sequence) - 1)
# for x in sequence:
#     print(x, end=' ')




# Uses python3
import sys

def optimal_sequence(n):
    sequence = []
    
    dp = [0]*(n+1)
    parent = [0]*(n+1)
    for i in range(1, n+1):
        curr_parent = i-1
        curr_dp = dp[curr_parent]+1
        if i %2 == 0:
            t_parent = i//2
            t_dp = dp[t_parent]+1
            if t_dp < curr_dp:
                curr_parent, curr_dp = t_parent, t_dp
        if i%3 == 0:
            t_parent = i//3
            t_dp = dp[t_parent]+1
            if t_dp < curr_dp:
                curr_parent, curr_dp = t_parent, t_dp
        parent[i],dp[i] = curr_parent, curr_dp


    # print(dp)
    # print(parent)
    while n>0:
        sequence.append(n)
        n = parent[n]


    return reversed(sequence)

input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')

# working until certain amount
# # Uses python3
# import sys

# def optimal_sequence(n):
#     sequence = []
#     T = dict()
#     parent = {}
#     def dp(i):

#         if i == 0:
#             return 0
#         if i not in T:
#             T[i] =1000000000
#             T[i] = min(T[i], dp(i-1)+1)
#             curr = T[i]
#             curr_parent = i-1
#             if i % 2==0:
#                 T[i] = min(T[i], dp(i//2)+1)
#                 if T[i]<curr:
#                     curr_parent, curr = i//2, T[i]
#             if i % 3==0:
#                 T[i] = min(T[i], dp(i//3)+1)
#                 if T[i]<curr:
#                     curr_parent, curr = i//3, T[i]

#             parent[i] = curr_parent
#         return T[i]
#     dp(n)

#     # print(T)
#     while n>0:
#         sequence.append(n)
#         n = parent[n]
#     # print(sequence)
#     # print('parent = ', parent)

#     # print(sequence)
#     return reversed(sequence)

# input = sys.stdin.read()
# n = int(input)
# sequence = list(optimal_sequence(n))
# print(len(sequence) - 1)
# for x in sequence:
#     print(x, end=' ')
