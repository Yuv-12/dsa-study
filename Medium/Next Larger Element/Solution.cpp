class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int>st;
        vector<int> res(arr.size());
        res[arr.size()-1] = -1;
        st.push(arr.size() -1);
        for(int i = arr.size()-2;i>=0;i--)
        {
            if(arr[i]<arr[st.top()])
            {
                res[i] = arr[st.top()];
                st.push(i);
            }
            else
            {
                while(!st.empty() && arr[i] >= arr[st.top()])
                    st.pop();
                
                if(st.empty())
                {
                    res[i] = -1;
                    st.push(i);
                }
                else
                {
                    res[i] = arr[st.top()];
                    st.push(i);
                }
            }
        }
        return res;
    }
};