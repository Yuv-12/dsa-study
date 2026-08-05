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
};*/

class Solution {
  public:
    vector<int> findCommon(Node* r1, Node* r2) {
        // code here
       stack<Node *> s1,s2;
        vector<int> res;
        while(true)
        {
            while(r1)
            {
                s1.push(r1);
                r1 = r1->left;
            }
            while(r2)
            {
                s2.push(r2);
                r2 = r2->left;
            }
            if(s1.empty() || s2.empty())
                break;
            Node *curr1 = s1.top();
            Node *curr2 = s2.top();
            
            if(curr1->data == curr2->data)
            {
                res.push_back(curr1->data);
                s1.pop();
                s2.pop();
                
                r1 = curr1->right;
                r2 = curr2->right;
            }
            else if(curr1->data < curr2->data)
            {
                s1.pop();
                r1 = curr1->right;
                r2  = NULL;
            }
            else
            {
                s2.pop();
                r2 = curr2->right;
                r1 = NULL;
            }
        }
        return res;
    }
};