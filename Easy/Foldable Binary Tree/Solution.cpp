/* Structure of a Binary Tree Node
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  bool isMirror(Node *r1,Node *r2)
  {
      if(r1==NULL && r2==NULL)
        return true;
    if(r1==NULL || r2==NULL)
        return false;
    
    return isMirror(r1->left,r2->right) && isMirror(r1->right,r2->left);
  }
    bool isFoldable(Node* root) {
        // code here
        if(root==NULL)
            return true;
        
        return isMirror(root->left,root->right);
    }
};