class Solution {
  public:
        bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> mpa;
        for(int x : a)
            mpa[x]++;
        
        for(int x: b)
        {
            if(mpa[x] > 0)
                mpa[x]--;
            else
                return false;
        }
        return true;
    }
    
};