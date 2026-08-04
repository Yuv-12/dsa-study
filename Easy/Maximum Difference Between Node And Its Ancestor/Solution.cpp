/* Structure of Binary Tree Node
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
  int solve(Node *root,int &max_diff)
  {
      if(root==NULL)
        return INT_MAX;
        
        if(root->left==NULL && root->right==NULL)
            return root->data;
        
        int leftmin = solve(root->left,max_diff);
        int rightmin = solve(root->right,max_diff);
        
        int minData = min(leftmin,rightmin);
        
        max_diff = max(root->data - minData,max_diff);
        return min(root->data,minData);
  }
    int maxDiff(Node* root) {
        // code here
        int max_diff = INT_MIN;
        solve(root,max_diff);
        return max_diff;
    }
};