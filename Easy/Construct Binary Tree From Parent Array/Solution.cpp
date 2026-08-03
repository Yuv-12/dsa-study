/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* createTree(vector<int>& parent) {
        // code here
        int n = parent.size();
        
        vector<Node * > nodes(n);
        for(int i = 0;i<n;i++)
        {
            nodes[i] = new Node(i);
        }
        
        Node *root = NULL;
        for(int i = 0;i<n;i++)
        {
            if(parent[i] == -1)
                root = nodes[i];
            
            else
            {
                Node *par = nodes[parent[i]];
                if(par->left == NULL)
                    par->left = nodes[i];
                else
                    par->right = nodes[i];
            }
        }
        return root;
    }
};
