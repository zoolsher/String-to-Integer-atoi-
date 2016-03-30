
class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0) return 0; 

        bool isNeg = false;
        long re = 0;
        int i=0,cnt;
        for(;i<str.length(); i++) if(str[i] != ' ') break; 

        if(str[i] == '-') 
            isNeg = true;
        else if (str[i] == '+') isNeg = false;
        else if(str[i] >= '0' && str[i] <= '9')
            re = str[i] - '0',cnt=1; 
        else return 0;

        i++;   
        for(; i < str.length(); i++)
        {
            if (cnt > 10) break; 
            if(str[i] < '0' || str[i] > '9')  break;  
            re = re*10 + (str[i] - '0'),cnt++;
        }


        if(re > INT_MAX && !isNeg) return INT_MAX; 
        else if(isNeg &&re*(-1) < INT_MIN) return INT_MIN;
        return isNeg?re*(-1):re;
    }
};
