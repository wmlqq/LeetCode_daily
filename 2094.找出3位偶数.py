from typing import List
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        res=set()
        for i in range(len(digits)):
            if digits[i]!=0:
                for j in range(len(digits)):
                    if j!=i:
                        for k in range(len(digits)):
                            if k!=i and k!=j:
                                if digits[k]%2==0 and digits[i]*100+digits[j]*10+digits[k] not in res:
                                    res.add(digits[i]*100+digits[j]*10+digits[k])
        res=list(res)
        res.sort()
        return res