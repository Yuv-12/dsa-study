class Solution {
  public:
    bool canRearrange(string& s) {
        // code here
        vector<int> freq(26,0);
        for(char ch : s)
            freq[ch-'a']++;
        
        priority_queue<pair<int,char>> pq;
        for(int i = 0;i<26;i++)
        {
            if(freq[i] > 0)
                pq.push({freq[i],'a'+i});
        }
        while(pq.size()>=2)
        {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            
            first.first--;
            second.first--;
            if(first.first > 0)
                pq.push(first);
            if(second.first > 0)
                pq.push(second);
        }
        if(!pq.empty() && pq.top().first>1)
            return false;
        
        return true;
    }
};