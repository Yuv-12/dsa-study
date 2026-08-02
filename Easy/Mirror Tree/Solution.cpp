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
    void mirror(Node* root) {
        // code here
        if(root==NULL)
            return ;
        
        else
        {
            Node *temp ;
            mirror(root->left);
            mirror(root->right);
            
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }
};