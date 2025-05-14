import bisect
from typing import List
class Solution:
    def greaterCount(self, sorted_arr, val):
        # 使用二分查找快速统计比val大的元素数量
        return len(sorted_arr) - bisect.bisect_right(sorted_arr, val)

    def resultArray(self, nums: List[int]) -> List[int]:
        arr1, arr2 = [], []
        # 维护两个有序数组
        sorted_arr1 = []
        sorted_arr2 = []

        for num in nums:
            if not sorted_arr1:
                sorted_arr1.append(num)
                arr1.append(num)
            elif not sorted_arr2:
                sorted_arr2.append(num)
                arr2.append(num)
            else:
                cnt1 = self.greaterCount(sorted_arr1, num)
                cnt2 = self.greaterCount(sorted_arr2, num)

                if cnt1 > cnt2:
                    bisect.insort(sorted_arr1, num)
                    arr1.append(num)
                elif cnt1 < cnt2:
                    bisect.insort(sorted_arr2, num)
                    arr2.append(num)
                else:
                    if len(arr1) > len(arr2):
                        bisect.insort(sorted_arr2, num)
                        arr2.append(num)
                    else:
                        bisect.insort(sorted_arr1, num)
                        arr1.append(num)
        return arr1 + arr2