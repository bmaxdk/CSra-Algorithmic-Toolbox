# Uses python3
def edit_distance(s, t):
    #write your code here
    T = [[float("inf")] * (len(t)+1) for _ in range(len(s)+1)]

    for i in range(len(s)+1):
        T[i][0] = i
    for j in range(len(t)+1):
        T[0][j] = j
    for i in range(1, len(s)+1):
        for j in range(1, len(t)+1):
            diff = 0 if s[i-1] == t[j-1] else 1
            T[i][j] = min(T[i-1][j]+1, T[i][j-1]+1, T[i-1][j-1]+diff)

    return T[len(s)][len(t)]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
