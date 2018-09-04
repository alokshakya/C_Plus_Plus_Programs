#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

vector<int> adj[MAX_N+1];
int startat[MAX_N+1],endat[MAX_N+1];
int status[MAX_N+1],status_size;
int tree[2*(MAX_N+1)],leftone[2*(MAX_N+1)],rightone[2*(MAX_N+1)];
int lazy[2*(MAX_N+1)];
int curmake;
int n;
void dfs(int at,int *done)
{

    //cout<<"at "<<at<<endl;
    if(done[at]==1)
        return;
    done[at]=1;
    status[status_size]=1;
    startat[at]=status_size;
    #ifdef DEBUG
    cout<<"startat of "<<at<<" is "<<startat[at]<<endl;
    #endif
    status_size++;
    vector<int>::iterator it=adj[at].begin();
    while(it!=adj[at].end())
    {
        dfs(*it,done);
        it++;
    }
    endat[at]=status_size-1;
    cout<<"node "<<at<<" : starts at : "<<startat[at]<<" : ends at : "<<endat[at]<<endl;
    #ifdef DEBUG
    cout<<"endat of "<<at<<" is "<<endat[at]<<endl;
    #endif
}
void make(int thisone,int atl,int atr)
{
    if(atl==atr)
    {
        tree[curmake]=1;
        leftone[curmake]=-1;
        rightone[curmake]=-1;
        curmake++;
        return;
    }
    int mid=(atl+atr)/2;

    curmake++;
    leftone[thisone]=curmake;
    make(curmake,atl,mid);
    if(mid+1<=atr)
    {
        rightone[thisone]=curmake;
        make(curmake,mid+1,atr);
    }
    else
    {
        rightone[thisone]=-1;
    }
    tree[thisone]=atr-atl+1;
    lazy[thisone]=0;
    return;
}
void  evallazy(int at,int atl,int atr)
{
    if(lazy[at]!=0)
    {
        if(lazy[at]==1)
        {
            tree[at]=atr-atl+1;
        }
        else if(lazy[at]==-1)
        {
            tree[at]=0;
        }
        if(leftone[at]!=-1)
            lazy[leftone[at]]=lazy[at];
        if(rightone[at]!=-1)
            lazy[rightone[at]]=lazy[at];
        lazy[at]=0;
    }
    return;
}
void command(int at,int atl,int atr,int targetl,int targetr,int type)
{

    evallazy(at,atl,atr);
    if(atl==targetl && atr==targetr)
    {
        if(leftone[at]!=-1)
            lazy[leftone[at]]=type;
        if(rightone[at]!=-1)
            lazy[rightone[at]]=type;
        if(type==1)
            tree[at]=atr-atl+1;
        else
            tree[at]=0;
        return;
    }
    int mid=(atl+atr)/2;

    if(mid>=targetl)
        command(leftone[at],atl,mid,targetl,MIN(targetr,mid),type);
    if(mid+1<=targetr)
        command(rightone[at],mid+1,atr,MAX(mid+1,targetl),targetr,type);
    evallazy(leftone[at],atl,mid);
    evallazy(rightone[at],mid+1,atr);
    tree[at]=tree[leftone[at]]+tree[rightone[at]];
    return;

}

int check(int at,int atl,int atr,int targetl,int targetr)
{
    #ifdef DEBUG
     //   cout<<" at "<<at<<" atl "<<atl<<" atr "<<atr<<" targetl "<<targetl<<" targetr "<<targetr<<endl;
   //     int ch;
     //   cin>>ch;
    #endif
    evallazy(at,atl,atr);
    if(atl==targetl && atr==targetr)
    {
        return tree[at];
    }
    int mid=(atl+atr)/2;
    int leftonew=0,rightonew=0;
    if(mid>=targetl)
        leftonew=check(leftone[at],atl,mid,targetl,MIN(targetr,mid));
    if(mid+1<=targetr)
        rightonew=check(rightone[at],mid+1,atr,MAX(mid+1,targetl),targetr);
    evallazy(leftone[at],atl,mid);//needed or not?
    evallazy(rightone[at],mid+1,atr);
    tree[at]=tree[leftone[at]]+tree[rightone[at]];
    return leftonew+rightonew;
}
void traverse(int at,int atl,int atr)
{
    cout<<"at: "<<at<<" atl: "<<atl<<" atr: "<<atr<<" lazy: "<<lazy[at]<<" value: "<<tree[at]<<"left: "<<leftone[at]<<" right:"<<rightone[at]<<endl;
    int mid=(atl+atr)/2;
    if(atl!=atr)
    {
        traverse(leftone[at],atl,mid);
        traverse(rightone[at],mid+1,atr);
    }
}
int main()
{

    int i,j,a,b,c,first;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>b;
        if(b==0)
            first=i;
        else
        {

            adj[i].push_back(b);
            adj[b].push_back(i);
        }
    }

    status_size=0;
    int done[MAX_N+1]={0};
    dfs(first,done);
    for(i=1;i<=n;i++)
        cout<<"ends "<<i<<" : "<<endat[i]<<endl;
    curmake=0;
    make(0,0,status_size-1);
    int q;
    cin>>q;
    while(q--)
    {
        int type,id;
        cin>>type>>id;
        switch(type)
        {
            case 1:
                if(startat[id]!=endat[id])
                    command(0,0,status_size-1,startat[id]+1,endat[id],1);
                break;
            case 2:
                if(startat[id]!=endat[id])
                    command(0,0,status_size-1,startat[id]+1,endat[id],-1);
                break;
            case 3:
                int ans;
                if(startat[id]!=endat[id])
                ans=check(0,0,status_size-1,startat[id]+1,endat[id]);
                else
                    ans=0;

                cout<<ans<<endl;

                break;
        }

    }

    return 0;
}
