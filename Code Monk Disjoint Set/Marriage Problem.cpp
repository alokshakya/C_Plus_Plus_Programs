#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const unsigned int M = 1000000007;
#define ll long long
#define mod 1000000007


class UnionFind {
    int *parent, *ranks, _size;
    vector<int> *child;
public:
    UnionFind(){
    }
    UnionFind(int size){

        parent = new int[size]; ranks = new int[size]; child=new vector<int>[size];
        for(int element = 0 ; element < size ; element++){
            parent[element] = element , ranks[element] = 0 ; child[element].push_back(element);
        }
        _size = size;
    }
    vector<int> childs(int element)
    {
        return child[element];
    }
    void resize(int size){
        parent = new int[size]; ranks = new int[size];
        for(int element = 0 ; element < size ; element++){
            parent[element] = element , ranks[element] = 0 ;
        }
        _size = size;
    }
    int find(int element){
        if(parent[element] == element){
            return element;
        }
        else{
            return parent[element] = find(parent[element]);          // Path Compression algorithm
        }
    }
    bool connected(int x,int y){
        if(find(x) == find(y)){
            return true;
        }
        else{
            return false;
        }
    }
    void merge(int x,int y){
        x = find(x);
        y = find(y);
        if(x != y){                                                   // Union by Rank algorithm
            if(ranks[x] > ranks[y]){
                parent[y] = x; child[x].push_back(y);ranks[x] ++ ;
            }
            else if(ranks[x] < ranks[y]){
                parent[x] = y; child[y].push_back(x);ranks[y] ++ ;
            }
            else{
                parent[x] = y; ranks[y] ++ ; child[y].push_back(x);
            }
            _size--;
        }
    }
    void clear(){
        delete [] parent; delete [] ranks;
    }
    int size(){
        return _size;
    }
};

/*long long C(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans =(ans* n - r + i);
        if(ans>M)
            ans=ans/M;
        ans /= i;
    }

    return ans;
}*/

ll power(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

int main(){
    int x,y,a,b,q1,q2,q3,i;

    ll ans = 0;
    vector<int> vec;
    vector<int>::iterator it;
    cin>>x>>y;
    UnionFind uf(x+y);
    cin>>q1;
    for( i=0;i<q1;++i)
    {
        cin>>a>>b;a--;b--;
        uf.merge(a,b);
    }


    cin>>q2;
    for( i=0;i<q2;++i)
    {
        cin>>a>>b;a=a+x-1;b=b+x-1;
        uf.merge(a,b);
    }
    cin>>q3;
    for( i=0;i<q3;++i)
    {
        cin>>a>>b;a=a-1;b=b+x-1;
        uf.merge(a,b);
    }
    for(i=0;i<(x+y);++i)
    {
        int ra=uf.find(i);
        it=find(vec.begin(),vec.end(),ra);
        if(it==vec.end())
        {
            vec.push_back(ra);
        }
    }
    for(it=vec.begin();it!=vec.end();++it)
    {
        int women=0,men=0;
        vector<int> v=uf.childs(*it);
        for(vector<int>::iterator itr=v.begin();itr!=v.end();++itr)
        {
            if(*itr>x-1)
                women++;
             else
                    men++;
        }
        int N=y-women;
        int R=men;
        //cout<<"men = "<<men<<" women = "<<N<<endl;
       // cout<<" combination :"<<power(N,R)<<endl;
          ans += (long long)(R*N);

            cout<<" ans after addition :"<<ans<<endl;
        // calculate ncr and sum


    }
    cout<<ans<<endl;

    return 0;
}
