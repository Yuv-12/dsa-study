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
  void inorder(Node *root, vector<int> &v)
  {
      if(root==NULL)
        return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
  }
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int> v;
        inorder(root,v);
        int n = v.size();
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            if(v[i]+v[j]==target)
                return true;
            else if(v[i]+v[j] > target)
                j--;
            else
                i++;
        }
       
        return false;
    }
};