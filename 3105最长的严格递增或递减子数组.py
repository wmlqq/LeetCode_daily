from typing import List
class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        res=1
        a=1
        b=1
        last=nums[0]
        for i in range(1,len(nums)):
            if nums[i]>last:
                a+=1
                b=1
                if a>res:
                    res=a
            elif nums[i]<last:
                b+=1
                a=1
                if b>res:
                    res=b
            else:
                a=1
                b=1
            last=nums[i]
        return res

