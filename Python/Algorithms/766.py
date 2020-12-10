class Solution:
    def isToeplitzMatrix(self, mat):
        rng_i, rng_j = range(len(mat)-1), range(len(mat[0])-1)
        for i in rng_i:
            for j in rng_j:
                if mat[i][j] != mat[i+1][j+1]:
                    return False
        return True
