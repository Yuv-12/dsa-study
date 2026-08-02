/*Structure of tree Node 
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
  int maxDiameter = 0;
  int height(Node* root) {
        // code here
        if(root==NULL)
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        maxDiameter = max(maxDiameter,leftHeight+rightHeight);
        return 1 + (max(leftHeight,rightHeight));
    }
    int diameter(Node* root) {
        // code here
        height(root);
        return maxDiameter;
        
    }
};