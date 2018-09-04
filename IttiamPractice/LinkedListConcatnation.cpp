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

    void insertAtFront(int n)
    {
        node *temp = new node;
        if(head == NULL)
        {
            temp->data=n;
            temp->next=NULL;
            head = temp;
            tail = temp;
        }
        else
        {
            temp->data=n;
            temp->next=head;
            head=temp;
        }


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
    void appendList(node* b_head,node* tail_of_b)
    {


        if(b == NULL)
        {
            cout<<" other list is empty "<<endl;
            return;
        }
            tail->next = b_head;
            tail=tail_of_b;
         //if you would make append a particular linked list again it will form cycle because linked list is address
    }

};

int main()
{
    linked_list a;
    linked_list b;
    linked_list c;
    int n;
    a.insertAtLast(1);
    a.insertAtLast(2);
    a.insertAtLast(3);
    b.insertAtLast(7);
    b.insertAtLast(8);
    b.insertAtLast(9);
    c.insertAtFront(2);
    c.printList();
    cout<<"\t testing append function \t"<<endl;
    cout<<"list a: ";a.printList();
    cout<<"list b: ";b.printList();
    //linked_list::concatenate(a.getHead(),b.getHead());
    a.appendList(b.getHead(),b.getTail());
    cout<<"\t list a after append function \t"<<endl;
    cout<<"list a: ";a.printList();
    cout<<"list b: ";b.printList();

    cout<<"\t testing again append function \t"<<endl;
    cout<<"list a: ";a.printList();
    cout<<"list c: ";c.printList();
    //linked_list::concatenate(a.getHead(),c.getHead());
    a.appendList(c.getHead(),c.getTail());
    cout<<"\t list a after append function \t"<<endl;
    cout<<"list a: ";a.printList();
    cout<<"list c: ";c.printList();
    a.insertAtLast(111);
    a.printList();
    return 0;
}
