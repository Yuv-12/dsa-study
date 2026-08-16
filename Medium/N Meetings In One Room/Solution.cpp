class Solution {
  public:
    static bool myComp(const pair<int,int> &a,const pair<int,int> &b)
    {
        return a.second < b.second;
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>> activitySet;
        for(int i = 0;i<start.size();i++)
        {
            activitySet.push_back({start[i],finish[i]});
        }
        if(activitySet.empty())
            return 0;
        sort(activitySet.begin(),activitySet.end(),myComp);
        pair<int,int> solution = activitySet[0];
        int count = 1;
        for(int i = 1;i<activitySet.size();i++)
        {
            int newSt = activitySet[i].first;
            int newFin = activitySet[i].second;
            if(newSt > solution.second)
            {
                count++;
                solution = {newSt,newFin};
            }
        }
        return count;
    }
};