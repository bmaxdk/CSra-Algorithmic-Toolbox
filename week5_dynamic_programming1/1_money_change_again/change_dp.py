# # Uses python3
# import sys

# def get_change(m):
#     #write your code here
#     return m // 4

# if __name__ == '__main__':
#     m = int(sys.stdin.read())
#     print(get_change(m))


# Uses python3
import sys

T = dict()
def get_change(m):
    #write your code here
    v = [1,3,4]
    if m == 0:
        return 0
    if m not in T:
        T[m] = 100000
        for i in range(len(v)):
            if v[i] <= m:
                T[m] = min(T[m], get_change(m-v[i])+1)
    return T[m]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))




# # # Uses python3
# import sys
# T = dict()
# def get_change(m):
#     #write your code here
#     v = [1,3,4]
#     # T = dict()
#     if m == 0:
#         return 0
#     if m not in T:
#         T[m] = 10000
#         for i in range(len(v)):
#             if v[i] <= m:
#                 T[m] = min(T[m], get_change(m-v[i])+1)
#     return T[m]

# if __name__ == '__main__':
#     m = 90
#     print(get_change(m))
