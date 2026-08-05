class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        auto it = lower_bound(arr.begin(),arr.end(),x);
        if(it == arr.end())
            return -1;
        else
            return it - arr.begin();
    }
};