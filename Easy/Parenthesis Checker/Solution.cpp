class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        unordered_map<char,char> pair =
        {
            {')' , '('},
            {'}' , '{'},
            {']' , '['}
        };
        
        for(char c : s)
        {
            if(c == '{' || c== '(' || c== '[')
                st.push(c);
            else
            {
                if(st.empty() || pair[c]!=st.top())
                    return false;
                
                st.pop();
            }
        }
        return st.empty();
    }
    
};