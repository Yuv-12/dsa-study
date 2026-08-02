/* Structure of binary tree node
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
  int height(Node *root)
  {
      if(root==NULL)
        return 0;
    
        return 1 +max(height(root->left),height(root->right));
  }
    bool isBalanced(Node* root) {
        // code here
        if(root==NULL)
            return true;
        
        int lefth = height(root->left);
        int righth = height(root->right);
        
        if(abs(lefth-righth) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
       
        
    }
};