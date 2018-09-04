#include <iostream>

using namespace std;
int main()
{
	// your code goes here
	int t,n,m;
	long a[1000005];

	cin>>t;
	while(t--)
	{
	    int i,count=0,x;
	    cin>>n>>m;

        for(i=0;i<=1000000;i++)
        a[i]=0;

        for(i=0;i<n;i++)
        {
        cin>>x;
        a[x-1]=1;

        }
        for(i=0;i<m;i++)
        {
            cin>>x;
            if(a[x-1]==1)
            {
                a[x-1]=0;

            count++;
            }
        }
        cout<<count<<endl;
	}
	return 0;
}
