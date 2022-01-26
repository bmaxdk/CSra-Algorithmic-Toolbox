# Uses python3
def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def get_maximum_value(dataset):
    #write your code here
    global op, nums,m_mat,M_mat
    nums = [0]
    op = []
    for i in range(len(dataset)):
        if i == 0 or i%2 == 0:
            nums.append(int(dataset[i]))
        else:
            op.append(dataset[i])

    #create matrix    
    m_mat = [[0 for _ in range(len(nums))] for _ in range(len(nums))]
    # [[0 for _ in range(len(w))] for _ in range(W+1)]
    M_mat = [[0 for _ in range(len(nums))] for _ in range(len(nums))]    


    #add diagonal
    for i in range(1, len(nums)):
        m_mat[i][i], M_mat[i][i] = nums[i], nums[i]

    for s in range(1, len(nums)-1):
        for i in range(1, len(nums)-s):
            j = i+s
            m_mat[i][j], M_mat[i][j] = MinAndMax(i,j)

    return M_mat[1][-1]

def MinAndMax(i,j):
    global op, nums,m_mat,M_mat

    mini = float("inf")
    maxi = -float("inf")
    for k in range(i, j):
        a = evalt(M_mat[i][k], M_mat[k+1][j], op[k-1])
        b = evalt(M_mat[i][k], m_mat[k+1][j], op[k-1])
        c = evalt(m_mat[i][k], M_mat[k+1][j], op[k-1])
        d = evalt(m_mat[i][k], m_mat[k+1][j], op[k-1])
        mini = min(mini, a,b,c,d)
        maxi = max(maxi, a,b,c,d)
    return (mini,maxi)


if __name__ == "__main__":
    # print(get_maximum_value("5-8+7*4-8+9"))
    print(get_maximum_value(input()))
