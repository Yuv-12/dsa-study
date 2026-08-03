/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int levSize = q.size();
            for(int i = 0;i<levSize;i++)
            {
                Node *curr = q.front();
                q.pop();
                
                if(curr->left==NULL && curr->right==NULL)
                    continue;
                int left = curr->left != NULL?curr->left->data:0;
                int right = curr->right!=NULL?curr->right->data:0;
                if(curr->data!=left+right)
                    return false;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return true;
    }
};