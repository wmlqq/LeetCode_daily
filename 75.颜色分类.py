class Solution:
    def sortColors(self, nums: List[int]) -> None:
        count=[0,0,0]
        for i in nums:
            count[i]+=1
        nums[:]= [0]*count[0]+[1]*count[1]+[2]*count[2]