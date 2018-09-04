#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Queue
{
    private: Node *head,*tail;int sz;
    public:
        Queue()
        {
            head=NULL; tail=NULL; sz=0;
        }
        void push(int n)
        {
            Node *temp = new Node;
            temp->data=n;
            temp->next=NULL;
            sz++;
            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
        }
        int front()
        {
            if(head!=NULL)
            {
                return head->data;
            }
            else
                cout<<"Empty Queue "<<endl;
        }
        void pop()
        {
            if(head!=NULL)
            {
                Node *temp=head;
                head=head->next;
                delete temp;
                sz--;
            }
            else
                cout<<"Empty Queue "<<endl;
        }
        bool empty()
        {
            return (head==NULL);
        }
        int size()
        {
            return sz;
        }
};
int main()
{
    Queue q;
    q.push(9);
    q.push(13);
    q.push(15);
    q.push(20);
    while(!q.empty())
    {
        cout<<q.front()<<" and q.size() is : "<<q.size()<<endl; q.pop();
    }
    return 0;
}
