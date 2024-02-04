class Solution {
public:
    Node *reverse(Node *head)
    {
        Node *curr=head,*prev=NULL;
        while(curr)
        {
            Node *next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1 && head1->data==0)
        {
            head1=head1->next;
        }
        while(head2 && head2->data==0)
        {
            head2=head2->next;
        }
        int n1=0,n2=0;
        Node *curr1=head1,*curr2=head2;
        while(curr1)
        {
            n1++;
            curr1=curr1->next;
        }
        while(curr2)
        {
            n2++;
            curr2=curr2->next;
        }
        if(n1 < n2)
        {
            swap(head1,head2);
        }
        else if(n1 == n2)
        {
            curr1=head1;
            curr2=head2;
            while(curr1)
            {
                if(curr1->data > curr2->data)
                {
                    break;
                }
                else if(curr1->data < curr2->data)
                {
                    swap(head1,head2);
                    break;
                }
                curr1=curr1->next;
                curr2=curr2->next;
            }
        }
        if(head1==NULL && head2==NULL)
        {
            return new Node(0);
        }
        //head1 has larger number
        //head2 has smaller number
        head1=reverse(head1);
        head2=reverse(head2);
        int borrow =0;
        Node *head=new Node(-1);
        Node *tail=head;
        while(head1 || head2)
        {
            int a = head1->data + borrow;
            int b=0;
            if(head2)
            {
                b=head2->data;
            }
            head1=head1->next;
            if(head2)
            {
                head2=head2->next;
            }
            
            if(a < b)
            {
                Node *temp=new Node(a+10-b);
                tail->next=temp;
                tail=temp;
                borrow = -1;
            }
            else
            {
                Node *temp = new Node(a-b);
                tail->next=temp;
                tail=temp;
                borrow=0;
            }
            
        }
        head=head->next;
        head = reverse(head);
        while(head && head->data == 0)
        {
            head=head->next;
        }
        if(head==NULL)
        {
            return new Node(0);
        }
        return head;
 
        return NULL;
    }
};
