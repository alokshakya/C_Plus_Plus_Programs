#include<iostream>
#include<queue>
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
    int n,k,a,b;
    cin>>n>>k;
    UnionFind uf(n);
    priority_queue<int,greater> Q;
    for(int j=1;j<=k;++j)
    {
        cin>>a>>b;
        a--;b--;
        uf.merge(a,b);
        for(int z=0;z<n;++z)
        {
//logic to be written which is left.
        }
    }
    cout << uf.size() << endl;
    return 0;
}
