class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        vector<string> words;
		string w = "";
		for(char ch : s)
		{
		    if(ch == '.')
		    {
		        if(!w.empty())
		        {
		            words.push_back(w);
		            w.clear();
		        }
		        
		    }
		    else
		        w += ch;
		}
		if(!w.empty())
		{
		    words.push_back(w);
		}
		string ans ="";
		for(int i = words.size()-1;i>=0;i--)
		{
		    ans+=words[i];
		    if(i!=0)
		        ans+='.';
		}
		return ans;
    }
};