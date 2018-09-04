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
            cout<<current->data<<"--> ";
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
    void appendList(node* b,node* tai)
    {


        if(b == NULL)
        {
            cout<<" other list is empty "<<endl;
            return;
        }
            tail->next = b;
            tail=tai;
            //traverse b to get last node to maintain tail property
           // setTail(b.getTail());
           // tail=b.getTail();
            /*while(tail->next!=NULL)
            {
                tail = tail->next;
            }*/


    }
    void insertAtFront(int n)
    {
        node *temp = new node;
        temp->data=n;
        temp->next=head;
        head=temp;
    }

    void insertAfterValue(int val,int data)
    {
        node *pos;
        pos=head;
        int found=0;
        while(pos->next!=NULL)
        {
            if(pos->data==val)
            {
                found=1;
                break;
            }
            pos=pos->next;
        }
        if(found==1)
        {
            node *temp=new node;
            temp->data=data;
            temp->next=pos->next;
            pos->next=temp;
        }
        else
        {
            cout<<"value "<<val<<" after which node to be inserted not found "<<endl;
        }
    }
    static void concatenate(node *a,node *b)
    {
        if( a != NULL && b!= NULL )
        {
            /*if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next,b);*/
            //*(a.getTail())->next=b;
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }
};

int main()
{
    linked_list a;
    linked_list b;
    linked_list c;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a.insertAtLast(i);
        b.insertAtFront(i);
        a.printList();
        b.printList();
        c.insertAtLast(1);
        if(i>1)
        {
            c.insertAfterValue(1,i+3);
            cout<<"c list : ";
            c.printList();
        }


    }

    c.insertAfterValue(1,105);
    c.printList();
    c.insertAfterValue(105,302);
    c.printList();
    c.insertAtFront(20);
    c.printList();
    c.insertAfterValue(20,25);
    c.printList();
    cout<<"test concatation function "<<endl;
    cout<<"a list : "; a.printList();
    cout<<"b list : "; b.printList();
    //linked_list::concatenate(a.getHead(),b.getHead());
    //linked_list::printList(a.getHead());
    a.appendList(b.getHead(),b.getTail());
    cout<<"after concatation function "<<endl;
    cout<<"a list : "; a.printList();
    /*
    //again appending to check tail property
    cout<<"test concatation function "<<endl;
    cout<<"a list : "; a.printList();
    cout<<"b list : "; b.printList();
    //linked_list::concatenate(a.getHead(),b.getHead());
    //linked_list::printList(a.getHead());
    a.appendList(b.getHead());
    cout<<"after concatation function "<<endl;
    cout<<"a list : "; a.printList();
    */
    return 0;
}
