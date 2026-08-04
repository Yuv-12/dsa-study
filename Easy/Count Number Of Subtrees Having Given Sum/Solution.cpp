/* Structure of tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
  int count;
  int solve(Node *root,int x)
  {
      if(root==NULL)
        return 0;
        
        int leftSum = solve(root->left,x);
        int rightSum = solve(root->right,x);
        int subTreeSum = leftSum + rightSum + root->data;
        if(subTreeSum == x)
            count++;
        
        return subTreeSum;
  }
    int countSubtrees(Node* root, int x) {
        // code here
        count = 0;
        solve(root,x);
        return count;
    }
};