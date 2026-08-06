/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(root ==NULL)
            return NULL;
        if(root == n1 || root== n2)
            return root;
        
        Node *lca1 = findLCA(root->left,n1,n2);
        Node *lca2 = findLCA(root->right,n1,n2);
        if(lca1!=NULL and lca2!=NULL)
            return root;
        if(lca1!=NULL)
            return lca1;
        else
            lca2;
    }
};