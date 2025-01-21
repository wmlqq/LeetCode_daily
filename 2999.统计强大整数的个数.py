class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        x, m = int(s), len(s)

        def ceil(y: int):
            sy = str(y)
            pre, suf = int("0" + sy[:-m]), int(sy[-m:])
            return pre + int(suf >= x)

        def count(y: int) -> int:
            n, res = len(str(y)), 0
            for i, d in enumerate(map(int, str(y))):
                if limit < d:
                    return res + pow(limit + 1, n - i)
                res += d * pow(limit + 1, n - i - 1)
            return res

        b, a = ceil(finish), ceil(start - 1)
        return count(b) - count(a)