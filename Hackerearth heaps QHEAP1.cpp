#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>,greater<T>>
{
  public:

      bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
       }
       else {
        return false;
       }
 }
};

int main()
{
    int t,a,b;
    cin>>t;
    custom_priority_queue<int> Q;
    while(t--)
        {
        cin>>a;
        if(a==1)
            {
            cin>>b;
                       Q.push(b);
        }
        if(a==2)
            {
            cin>>b;
            Q.remove(b);

        }
        if(a==3)
        {
            cout<<Q.top()<<endl;
        }


    }


return 0;
 }
