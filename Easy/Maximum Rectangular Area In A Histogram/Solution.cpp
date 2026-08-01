class Solution {
  public:
 
    int getMaxArea(vector<int> &arr) {
        // code here
        int res = 0;
        stack<int> st;
        int n = arr.size();
        for(int i =0;i<n;i++)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
            {
                int top = st.top();
                st.pop();
                int curr = arr[top] * (st.empty()?i:i-st.top()-1);
                res = max(res,curr);
            }
            st.push(i);
        }
        while(!st.empty())
            {
                int top = st.top();
                st.pop();
                int curr = arr[top] * (st.empty()?n:n-st.top()-1);
                res = max(res,curr);
            }
        return res;
    }
};
