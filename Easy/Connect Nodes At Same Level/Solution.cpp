/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

*/

class Solution {
  public:
    Node* connect(Node* root) {
        // code here
        queue<Node  *> q;
        q.push(root);
        root->nextRight = NULL;
        while(!q.empty())
        {
            int levSize = q.size();
            for(int i = 0;i<levSize;i++)
            {
                Node *curr = q.front();
                q.pop();
                if(i<levSize-1)
                {
                    curr->nextRight = q.front();
                }
                else
                {
                    curr->nextRight=NULL;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return root;
    }
};