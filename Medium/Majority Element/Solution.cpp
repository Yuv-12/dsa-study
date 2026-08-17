class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int candidate = -1;
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(count==0)
            {
                candidate = arr[i];
                count = 1;
            }
            else if(candidate == arr[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
       count = 0;
        for(int x : arr)
        {
            if(candidate==x)
            {
                count++;
            }
        }
        if(count > n/2)
            return candidate;
        else
            return -1;
    }
};