class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                int top = st.top();
                st.pop();
                int len = st.empty()?i:i-st.top()-1;
                res[len-1] = max(res[len-1],arr[top]);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            int len = st.empty()?n:n-st.top()-1;
            res[len-1] = max(res[len-1],arr[top]);
        }
        for(int i = n-2;i>=0;i--)
        {
            res[i] = max(res[i],res[i+1]);
        }
        return res;
    }
};