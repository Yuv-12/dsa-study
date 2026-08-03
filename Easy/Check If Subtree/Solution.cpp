/* Structure of binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
      vector<int> buildLPS(string s)
      {
          
          int n = s.length();
          int len = 0;
          vector<int> lps(n,0);
          int i = 1;
          while(i<n)
          {
              if(s[i] == s[len])
                {
                    lps[i] = len+1;
                    len++;
                    i++;
                }
                else
                {
                    if(len==0)
                    {
                        lps[i] = 0;
                        i++;
                    }
                    else
                        len = lps[len-1];
                }
          }
          return lps;
          
      }
      bool kmpSearch(string &text,string &pattern)
      {
          vector<int> lps = buildLPS(pattern);
          int n = text.size();
          int m = pattern.size();
          int i = 0;
          int j = 0;
          while(i<n)
          {
              if(text[i] == pattern[j])
                {
                    i++;
                    j++;
                }
                if(j==m)
                    return true;
                else if(i<n && text[i]!=pattern[j])
                {
                    if(j==0)
                        i++;
                    else
                        j= lps[j-1];
                }
          }
          return false;
      }
      void serialize(Node *root,string &s)
      {
          if(root==NULL)
          {
              s += "#,";
              return;
          }
          
          s += to_string(root->data)+',';
          serialize(root->left,s);
          serialize(root->right,s);
            
      }
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        
        string tree1 = ",";
        string tree2 = ",";
        serialize(root1,tree1);
        serialize(root2,tree2);
        return kmpSearch(tree1,tree2);
    }
};