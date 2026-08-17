class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cand1 = -1;
        int cand2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(int x : arr)
        {
            if(cand1 == x)
                count1++;
            else if(cand2 == x)
                count2++;
            else if(count1==0)
            {
                cand1 = x;
                count1++;
            }
            else if(count2==0)
            {
                cand2 = x;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> res;
        count1 = 0;
        count2 = 0;
        for(int x : arr)
        {
            if(cand1 == x)
                count1++;
            if(cand2==x)
                count2++;
        }
        if(count1 > n/3)
            res.push_back(cand1);
        if(count2 > n/3 && cand1 != cand2)
            res.push_back(cand2);
        
        if(res.size() == 2 && res[0] > res[1])
            swap(res[0],res[1]);
        return res;
    }
};