#include<bits/stdc++.h>
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
using namespace std;
int mi,ma,sum,n;
vector<int> vec;
vector<vector<int>> seq;
void fun(int minR,int cou,int sumOfList)
{

    if(sumOfList==sum )
    {
        vector<int> ve,ve2;
        foreach(vec,it)
        {
            cout<<(*it)<<" ";
            ve.push_back((*it));
           // ve2.push_back((*it));

        }


        cout<<endl;
        //seq.push_back(ve);
        return;
    }
   if(cou==ma)
    return;


    for(int j=minR;j<=ma;j++)
    {
        vec.push_back(j);
        fun(j,cou+1,sumOfList+j);
        vec.erase(vec.end()-1);//backtrack the number last time entered
    }
}
int main()
{

    cout<<"Enter sum required : "; cin>>sum;
    mi=1;ma=sum;
    //cout<<"Min value : "; cin>>mi;
    //cout<<"Max Value : ";  cin>>ma;//cout<<"Numbers : "; cin>>n;
    cout<<"All possible combinations are : \n";
    fun(mi,0,0);

    return 0;
}
