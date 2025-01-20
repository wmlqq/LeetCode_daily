from curses.ascii import isdigit

class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.strip();
        if not s:return 0;
        result='';
        if s[0]=='-':sign=-1;s=s[1:];
        elif s[0]=='+':sign=1;s=s[1:];
        else: sign=1;
        for i,char in enumerate(s):
            if char.isdigit():
                result+=char;
            else:break;
        if not result:return 0;
        intresult=int(result)*sign;
        if intresult>2**31-1:return 2**31-1;
        elif intresult<-2**31:return -2**31;
        else:return intresult;
