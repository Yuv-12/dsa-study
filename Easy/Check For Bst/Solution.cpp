/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    
     void inorder(Node *root,bool &isBST,int &prevMax)
     {
         if(root==NULL)
            return;
            
        inorder(root->left,isBST,prevMax);
        int curr = root->data;
        if(curr<=prevMax)
            isBST = false;
        else
            prevMax = curr;
        inorder(root->right,isBST,prevMax);
     }
    bool isBST(Node* root) {
        // code here
        bool isBST = true;
        int prevMax = INT_MIN;
        inorder(root,isBST,prevMax);
        return isBST;
    }
};