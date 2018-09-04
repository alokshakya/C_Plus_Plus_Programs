#include<bits/stdc++.h>
using namespace std;
/* Function to get minimum number of trials needed in worst
  case with n eggs and k floors */
int eggDrop(int n, int k)
{
    /* A 2D table where entery eggFloor[i][j] will represent minimum
       number of trials needed for i eggs and j floors. */
    int eggFloor[n+1][k+1];
    int res;
    int i, j, x;

    // We need one trial for one floor and0 trials for 0 floors
    for (i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    // We always need j trials for one egg and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    // Fill rest of the entries in table using optimal substructure
    // property
    for (int egg = 2; egg <= n; egg++)
    {
        for (int fl = 2; fl <= k; fl++)
        {
            eggFloor[egg][fl] = INT_MAX;
            if(egg>fl) //eggs more than floor doesn't help this is equal to previous egg-1 calculated value
            {
                eggFloor[egg][fl]=eggFloor[egg-1][fl];
            }
            else
            {
                for (x = 1; x <= fl; x++)
                {
                    eggFloor[egg][fl]=min(eggFloor[egg][fl],(1+max(eggFloor[egg-1][x-1], eggFloor[egg][fl-x])));
                }
            }
        }
    }

    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int re=eggDrop(n,k);
        cout<<re<<endl;
    }

    return 0;
}
