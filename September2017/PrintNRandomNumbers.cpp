#include<bits/stdc++.h>
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
using namespace std;
int mi,ma,sum,n;
vector<int> vec;
vector<vector<int>> seq;
void fun(int minR,int noOfNumbers,int sumOfList)
{

    if(sumOfList==sum && noOfNumbers==n)
    {
        vector<int> ve;
        foreach(vec,it)
        {
            cout<<(*it)<<" ";
            ve.push_back((*it));

        }

        cout<<endl;
        seq.push_back(ve);
        return;
    }

    if (noOfNumbers==n)
        return;

    for(int j=minR;j<=ma;j++)
    {
        vec.push_back(j);
        fun(j,noOfNumbers+1,sumOfList+j);
        vec.erase(vec.end()-1); //backtrack the number last time entered
    }
}
int main()
{
    /*
    sum=40,mi=5,ma=10,n=5
5 5 10 10 10
5 6 9 10 10
5 7 8 10 10
5 7 9 9 10
5 8 8 9 10
5 8 9 9 9
6 6 8 10 10
6 6 9 9 10
6 7 7 10 10
6 7 8 9 10
6 7 9 9 9
6 8 8 8 10
6 8 8 9 9
7 7 7 9 10
7 7 8 8 10
7 7 8 9 9
7 8 8 8 9
8 8 8 8 8
    */
    cout<<"Enter sum required : "; cin>>sum;
    cout<<"Min value : "; cin>>mi;
    cout<<"Max Value : ";  cin>>ma;cout<<"Numbers : "; cin>>n;
    cout<<"All possible combinations are : \n";
    fun(mi,0,0);
    int siz=seq.size();
    int ra=rand()%(siz-1);
    vector<int> pr=seq[ra];
    foreach(pr,t)
    cout<<*(t)<<" ";
    cout<<endl;
    return 0;
}
