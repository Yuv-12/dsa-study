/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void traverse(Node *root,int d,unordered_set<int> &st)
    {
        if(root==NULL)
            return;
        st.insert(d);
        traverse(root->left,d-1,st);
        traverse(root->right,d+1,st);
    }
    int verticalWidth(Node* root) {
        // code here
        if(root==NULL)
            return 0;
        unordered_set<int>st;
        traverse(root,0,st);
        return st.size();
    }
};