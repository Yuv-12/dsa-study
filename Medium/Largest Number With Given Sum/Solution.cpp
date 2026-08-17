class Solution {
  public:
    string largestNumber(int n, int s) {
        // code here
        if(s>n*9 || s<0)
            return "-1";
            
        string res = "";
        for(int i = 0;i<n;i++)
        {
            int digit = min(9,s);
            res += to_string(digit);
            s -= digit;
        }
        return res;
    }
};