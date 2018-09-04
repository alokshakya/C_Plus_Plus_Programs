#include<iostream>
#include<cmath>
using namespace std;

class UnionFind {
    int *parent, *ranks, _size;
public:
    UnionFind(){
    }
    UnionFind(int size){
        parent = new int[size]; ranks = new int[size];
        for(int element = 0 ; element < size ; element++){
            parent[element] = element , ranks[element] = 0 ;
        }
        _size = size;
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
      int getrank(int element){
      return ranks[element];
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
                parent[y] = x;
            }
            else if(ranks[x] < ranks[y]){
                parent[x] = y;
            }
            else{
                parent[x] = y; ranks[y] ++ ;
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


int main(){
    int t,n,q,i,j,a,b,f1,f2;
        cin>>n>>q;
        UnionFind uf(n);
        for(j=1;j<=q;++j)
        {
                cin>>a>>b;
                a--;b--;
                if(!uf.connected(a,b))
                {
                   uf.merge(a,b);
                }
                int diff=abs(uf.getrank(a)-uf.getrank(b));
             if(uf.size()==1)
                cout<<"0"<<endl;
             else
                cout<<diff<<endl;
        }
    return 0;
}
