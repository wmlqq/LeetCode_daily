from typing import List
class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        res=0
        for i in range(len(nums)):
            count=0
            j=i
            while j!=0:
                if j%2==1:
                    count+=1
                j=j//2
            if count==k:
                res+=nums[i]
        return res