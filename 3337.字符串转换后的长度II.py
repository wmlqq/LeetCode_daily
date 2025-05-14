MOD = 10 ** 9 + 7
from typing import List
class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        if t == 0:
            return len(s) % MOD

        # 初始化字符频率
        count = [0] * 26
        for c in s:
            count[ord(c) - 97] += 1

        # 构建转移矩阵：M[c][d] 表示字符c替换一次生成d的数量
        M = [[0] * 26 for _ in range(26)]
        for c in range(26):
            m = nums[c]
            for j in range(m):
                d = (c + j + 1) % 26  # 关键修复点：+1 表示下一个字符
                M[c][d] += 1

        # 矩阵快速幂核心实现
        def matrix_mult(a, b):
            res = [[0] * 26 for _ in range(26)]
            for i in range(26):
                for k in range(26):
                    if a[i][k] == 0: continue
                    for j in range(26):
                        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD
            return res

        def matrix_pow(mat, power):
            result = [[1 if i == j else 0 for j in range(26)] for i in range(26)]  # 单位矩阵初始化
            while power > 0:
                if power % 2 == 1:
                    result = matrix_mult(result, mat)
                mat = matrix_mult(mat, mat)
                power //= 2
            return result

        M_t = matrix_pow(M, t)

        # 计算最终总长度
        total = 0
        for c in range(26):
            for d in range(26):
                total = (total + count[c] * M_t[c][d]) % MOD
        return total