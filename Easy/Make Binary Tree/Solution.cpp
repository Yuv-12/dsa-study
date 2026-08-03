/*
class NodeLL {
  public:
    int data;
    NodeLL *next;

    NodeLL(int x) {
        data = x;
        next = NULL;
    }
};
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void insert(Node * root,int key)
    {
       
    }
    Node *linkedListToBinaryTree(NodeLL *head) {
        // code here
        if(head==NULL)
            return NULL;
        
        Node *root = new Node(head->data);
        queue<Node *> q;
        q.push(root);
        NodeLL *curr = head->next;
        while(curr!=NULL)
        {
            int key = curr->data;
            Node * parent = q.front();
            q.pop();
            Node * leftChild = new Node(curr->data);
            parent->left = leftChild;
            q.push(leftChild);
            
            curr = curr->next;
            if(curr !=NULL)
            {
                Node * rightChild = new Node(curr->data);
            parent->right = rightChild;
            q.push(rightChild);
            curr = curr->next;
            }
        }
        return root;
    }
};