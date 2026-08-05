/* Node Structure
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
   unordered_set<Node *> st;
   void traverse(Node *root,vector<Node *>&v,int k)
   {
       if(root==NULL)
        {
            return;
        }
        v.push_back(root);
        if(root->left==NULL && root->right == NULL)
        {
            if(v.size()>k)
            {
                st.insert(v[v.size()-1-k]);
            }
        }
        traverse(root->left,v,k);
        traverse(root->right,v,k);
        v.pop_back();
   }
    int kthFromLeaf(Node* root, int k) {
        // code here.
        vector<Node *> v;
        traverse(root,v,k);
        return st.size();
    }
};