/* Structure of binary tree node
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
  int solve(Node *root,int &globalMax)
  {
      if(root==NULL)
        return 0;
        
    int left = max(0,solve(root->left,globalMax));
    int right = max(0,solve(root->right,globalMax));
    
    int throughNode = root->data + left + right;
    
    globalMax= max(globalMax,throughNode);
    
    return root->data +max(left,right);
    
  }
    int findMaxSum(Node *root) {
        // code here
        int globalMax = INT_MIN;
        solve(root,globalMax);
        return globalMax;
    }
};