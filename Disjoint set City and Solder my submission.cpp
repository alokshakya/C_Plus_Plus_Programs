#include<iostream>
// this solution gives the runtime error
using namespace std;

class UnionFind {
    int *parent, *ranks, _size;
public:
    UnionFind(){
    }
    UnionFind(int size){
        parent = new int[size+1]; ranks = new int[size+1];
        for(int element = 1 ; element <= size ; element++){
            parent[element] = element , ranks[element] = 0 ;
        }
        _size = size;
    }
    void resize(int size){
        parent = new int[size+1]; ranks = new int[size+1];
        for(int element = 1 ; element <= size ; element++){
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
                                                        // Union by Rank algori
                parent[x] = y; ranks[y] ++ ;

            _size--;
    }
    void makeL(int x)
    {
        int w=find(x);
        parent[w]=x;
    }
    void clear(){
        delete [] parent; delete [] ranks;
    }
    int size(){
        return _size;
    }
};


int main(){
    int n,m,c,a,b;
    cin>>n>>m;
    UnionFind uf(n);
    for(int i=0; i<m;++i)
    {
        cin>>c;
        if(c==1)
        {
            cin>>a>>b;
            uf.merge(a,b);
        }
        else if(c==2)
        {
            cin>>a;
            uf.makeL(a);


        }
        else if(c==3)
        {
            cin>>a;
            cout<<uf.find(a)<<endl;
        }
    }
    return 0;
}
