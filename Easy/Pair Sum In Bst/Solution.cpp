/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void inorder(Node *root,unordered_set<int> &st)
  {
      if(root==NULL)
        return;
    inorder(root->left,st);
    st.insert(root->data);
    inorder(root->right,st);
  }
    bool findTarget(Node *root, int target) {
        // your code here.
        unordered_set<int> st;
        inorder(root,st);
        if(st.size()>1)
        {
             for(auto it = st.begin();it!=st.end();it++)
        {
            int toSearch = target - *it;
            if(st.find(toSearch)!=st.end())
                return true;
        }
        }
       
        return false;
    }
};