#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class UnionFind {
    int *parent, *ranks, _size;
public:
    UnionFind(){
    }
    UnionFind(int size){
        parent = new int[size]; ranks = new int[size];
        for(int element = 0 ; element < size ; element++){
            parent[element] = element , ranks[element] = 1 ;
        }
        _size = size;
    }
    void resize(int size){
        parent = new int[size]; ranks = new int[size];
        for(int element = 0 ; element < size ; element++){
            parent[element] = element , ranks[element] = 1 ;
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
      int rank(int element){
        int a=find(element);
        return ranks[a];

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
          if(x!=y)
          {
                if(ranks[x] > ranks[y]){
                parent[y] = x; ranks[x]++;
            }
            else if(ranks[x] < ranks[y]){
                parent[x] = y; ranks[y] ++ ;
            }
            else{
                parent[x] = y; ranks[y] ++ ;
            }
            _size--;
          }                                                 // Union by Rank algorithm


    }
    void clear(){
        delete [] parent; delete [] ranks;
    }
    int size(){
        return _size;
    }
};


int main(){
    const unsigned int M = 1000000007;
    unsigned long long ans = 1;
    vector<int> vec;
    vector<int> ranks;
    vector<int>::iterator it;
    int n,m,c,d;
    cin>>n>>m;
    UnionFind uf(n);
    for(int i=0;i<m;++i)
    {
        cin>>c>>d;c--;d--;
        uf.merge(c,d);
    }
    for(int j=0;j<n;++j)
    {
        int ra=uf.find(j);
        it=find(vec.begin(),vec.end(),ra);
        if(it==vec.end())
        {
            vec.push_back(ra);
            ranks.push_back(uf.rank(ra));
        }

    }
    for(it=ranks.begin();it!=ranks.end();++it)
        ans=ans*(*it)%M;
        cout<<ans<<endl;

    return 0;
}
