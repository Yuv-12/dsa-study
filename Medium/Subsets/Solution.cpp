class Solution {
  public:
    void sub(vector<int>&arr,vector<vector<int>>&res,vector<int> &curr,int index)
    {
        if(index==arr.size())
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(arr[index]);
        sub(arr,res,curr,index+1);
        curr.pop_back();
        sub(arr,res,curr,index+1);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<vector<int>> res;
        vector<int> curr;
        sub(arr,res,curr,0);
        return res;
    }
};