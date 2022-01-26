# Uses python3
import sys

def optimal_weight(W, w):
    # write your code here
    w = [0]+w

    mat = [[0 for _ in range(len(w))] for _ in range(W+1)]
    # print(mat)

    for i in range(1, len(w)):
        for j in range(1, W+1):
            mat[j][i] = mat[j][i-1]
            if w[i] <= j:
                val = mat[j-w[i]][i-1]+w[i]
                if mat[j][i] < val:
                    mat[j][i] = val
    #         print(mat)
    # print(mat)
    return mat[-1][-1]



if __name__ == '__main__':
    # input = '10 3 1 4 8'
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))

    # W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
