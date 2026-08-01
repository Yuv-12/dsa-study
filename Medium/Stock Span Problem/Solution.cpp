class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<int> st;
        st.push(0);
        vector<int> res;
        res.push_back(1);
        for(int i = 1;i<arr.size();i++)\
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            
            int span = st.empty()?i+1:i - st.top();
            res.push_back(span);
            st.push(i);
        }
        return res;
    }
};