#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
unordered_map<int,int> mp;
int a[100100]={0};
int main()
{
    priority_queue<pair<int,int> >P;
    int n,i,x,m;
    int k=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(mp.count(x)==0) // checks whether x is in map
            // returns 1 if the container contains an element whose key is equivalent to x, or zero otherwise.
        {
            mp[x]=k;//insert k in map at key x
           // cout<<"value of mp["<<x<<"] "<<mp[x]<<" and value of k "<<k<<endl;
            a[k]++; // increase value of element in array at position k
           // cout<<"value of a k ["<<k<<"] "<<a[k]<<" and value of k "<<k<<endl;
            k++; // increase value of k by 1.
            //cout<<"value of a x ["<<x<<"] "<<a[x]<<" and value of k "<<k<<endl;
           // cout<<"value of a a[mp[x]]  for x=["<<x<<"] "<<a[mp[x]]<<" which is used for sorting and value of k "<<k<<endl;
        }
        else // key x already exists in map
        {
            a[mp[x]]++; // get the value of x key in map (which works as index of array)
        // increase value for that index
        //increase value of element in array at position mp[x]
        }
        P.push(make_pair(a[mp[x]],x));// push new element in queue
       // cout<<"size of map " << mp.size()<<" size of queue "<<P.size()<<"  and value of k "<<k<<endl;
        cout<<P.top().second<<" "<<P.top().first<<endl;
    }
    return(0);
}
