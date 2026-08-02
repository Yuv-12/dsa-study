/*  Structure of a Binary Tree
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
    int maxWidth(Node* root) {
        // code here
        if(root==NULL)
            return 0;
        queue<Node *> q;
        q.push(root);
        int maxW = 0;
        while(!q.empty())
        {
            int currSize = q.size();
            maxW = max(currSize,maxW);
            for(int i = 0;i<currSize;i++)
            {
            Node *temp = q.front();
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            
            if(temp->right!=NULL)
                q.push(temp->right);
            }
        }
        return maxW;
    }
};