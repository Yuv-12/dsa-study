/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        Node *curr1 = head1;
        Node *curr2 = head2;
        int n1 = 0;
        int n2 = 0;
        while(curr1)
        {
            n1++;
            curr1 = curr1->next;
        }
        while(curr2)
        {
            n2++;
            curr2 = curr2->next;
        }
        int pos = abs(n1-n2);
        curr1 = head1;
        curr2 = head2;
        if(n1>n2)
        {
            while(pos!=0)
            {
                curr1 = curr1->next;
                pos--;
            }
        }
        else
        {
            while(pos!=0)
            {
                curr2 = curr2->next;
                pos--;
            }
        }
        while(curr1 && curr2)
        {
            if(curr1==curr2)
                return curr1;
            else
            {
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
        }
    }
};