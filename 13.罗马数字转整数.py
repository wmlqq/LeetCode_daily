class Solution:
    def romanToInt(self, s: str) -> int:
        all={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        res=0
        for i in range(len(s)):
            if i<len(s)-1 and all[s[i]]<all[s[i+1]]:
                res-=all[s[i]]
            else:
                res+=all[s[i]]
        return res