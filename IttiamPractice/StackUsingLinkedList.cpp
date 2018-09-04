#include<iostream>
using namespace std;
struct StackNode
{
    int data;
    StackNode *next;
};
class Stack
{
    private: StackNode *tail; int siz;
    public:
        Stack()
        {
            tail=NULL;
            siz=0;
        }
        void push(int n)
        {
            StackNode *temp=new StackNode;
            temp->data=n;
            temp->next=tail;
            tail=temp;
            siz++;
        }
        int top()
        {
            if(tail!=NULL)
            {
                return tail->data;
            }
            else
                cout<<"Empty Stack "<<endl;
        }
        void pop()
        {
            if(tail!=NULL)
            {
                StackNode *temp=tail;
                tail=tail->next;
                delete temp;
                siz--;

            }
            else
                cout<<"Empty Stack "<<endl;
        }
        bool empty()
        {
            return tail==NULL;
        }
        int size()
        {
            return siz;
        }
};
int main()
{
    Stack st;
    st.push(3);
    st.push(7);
    st.push(1);
    while(!st.empty())
    {
        cout<<st.top()<<" and size : "<<st.size()<<endl; st.pop();
    }
    cout<<"Enter Number to reverse "<<endl;
    int no; cin>>no;
    Stack b;
    while(no>0)
    {
         b.push(no%10);
         no=no/10;
    }
    Stack c;
    while(!b.empty())
    {
        //cout<<b.top();
        c.push(b.top());
         b.pop();
    }
    while(!c.empty())
    {
        cout<<c.top();
         c.pop();
    }
    return 0;
}
