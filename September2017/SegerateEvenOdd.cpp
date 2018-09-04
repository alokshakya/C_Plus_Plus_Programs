#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    node* getHead()
    {
        return head; //utility function to return pointer to head node
    }
    node* getTail()
    {
        return tail; // returns pointer to tail
    }
    void setTail(node* t)
    {
        tail=t;
    }
    void printList()
    {
        if(head==NULL)
        {
            cout<<"Empty LinkedList "<<endl;
            return;
        }
        node *current;
        current=head;
        while(current!=NULL)
        {
            if(current->next==NULL)
            cout<<current->data<<endl;
            else
            cout<<current->data<<" ";
            current=current->next;
        }
    }

    void insertAtLast(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void insertAtFront(int n)
    {
        node *temp = new node;
        temp->data=n;
        temp->next=head;
        head=temp;
    }
    void segerateEvenOdd()
    {
        node *current,*prev,*odd,*oddT;
        current=prev=head; odd=oddT=NULL;
        while(current!=NULL)
        {
            int dat=current->data;
            if(dat%2==0) //even case
            {
                node *tmp = new node;
                tmp->data = dat;
                tmp->next = NULL;
                if(oddT==NULL)
                {
                    odd=tmp;
                    oddT=odd;
                }
                else
                {
                    oddT->next=tmp;
                    oddT=oddT->next;

                }
                //now delete this node from previous node
                prev->next=current->next;
                node *fr=current;
                current=current->next;
                delete fr;
            }
            else
            {
                prev=current;
                current=current->next;
            }
        }
        oddT->next=head;
        head=odd;

    }
    void deleteList()
    {
            node *current;
            current=head;
            while(current!=NULL)
            {
               node *fr=current;
                current=current->next;
                delete fr;
            }
    }



};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        linked_list a;
        cin>>n;
        for(i=0;i<n;i++)
            {
                int x; cin>>x; a.insertAtLast(x);
            }
        a.segerateEvenOdd();
        a.printList();
        a.deleteList();
    }


    return 0;
}
