/* Structure of tree Node
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
 
  void inorder(Node *root,int low,int high,set<int> &st)
  {
      if(root==NULL)
        return;
        
        inorder(root->left,low,high,st);
        if(root->data >= low && root->data<=high)
            st.insert(root->data);
        inorder(root->right,low,high,st);
  }
    vector<int> nodesInRange(Node *root, int low, int high) {
        // code here 
       set<int> st;
        inorder(root,low,high,st);
        vector<int> res;
        for(auto it = st.begin();it!=st.end();it++)
        {
            res.push_back(*it);
        }
        return res;
    }
};