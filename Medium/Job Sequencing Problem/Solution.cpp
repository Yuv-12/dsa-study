class Solution {
  public:
  int find(vector<int>&parent,int i)
  {
      if(parent[i] == i)
        return i;
        return parent[i] = find(parent,parent[i]);
  }
    static bool myCmp(const pair<int,int>&a,const pair<int,int>&b)
    {
        return a.second > b.second;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> jobs;
        int maxDeadline = 0;
        for(int i =0;i<deadline.size();i++)
        {
            jobs.push_back({deadline[i],profit[i]});
            maxDeadline = max(maxDeadline,deadline[i]);
        }
        sort(jobs.begin(),jobs.end(),myCmp);
        vector<int> parent(maxDeadline+1);
        for(int i= 0;i<=maxDeadline;i++)
        {
            parent[i] = i;
        }
        int count = 0;
        int total_profit = 0;
        for(auto job : jobs)
        {
            int d = job.first;
            int p = job.second;
            int availableSlot = find(parent,d);
            if(availableSlot>0)
            {
                count++;
                total_profit += p;
                parent[availableSlot] = find(parent,availableSlot-1);
            }
        }
        return {count,total_profit};
    }
};