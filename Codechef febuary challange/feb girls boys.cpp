/*
this code is contributed by alok_shakya
*/
#include<iostream>
#include<vector>
#define boost1 ios_base::sync_with_stdio(0)
#define boost2 cin.tie(0)
using namespace std;
int main()
{
    boost1;
    boost2;
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;++i)
        {
            cin>>a[i];
        }
        i=0;
        int c=0;
        vector<int> vec;
        while(i<n-1)
        {
            if(a[i]==0 && a[i+1]==1)
            {
                vec.push_back(i);
                c++;
                i+=2;
            }
            i++;
        }
        int flag=0;
        int co=0;
        while(c>0 || flag==0)
        {
            flag=1;
            i=0;
            int z=0;
            for(vector<int>::iterator it=vec.begin();it!=vec.end();++it)
            {

            }
           while(i<n-1)
           {
               if(a[i]==0 && a[i+1]==1)
               {
                   z++;
                   a[i]=1; a[i+1]=0;
                   i+=2;
               }
               else
               i++;
           }
         /*  // print array after swapping
           for(int k=0;k<n;++k)
            cout<<a[k]<<" ";
           cout<<endl; */
           co++;
           c=z;

        }
        if(co!=0)
            co=co-1;
        cout<<co<<endl;
    }
    return 0;
}
