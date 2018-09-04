#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define MAX 1<<30
//Posibles moves
int positionsX[4]= {0,-1,0,1};
int positionsY[4]= {-1,0,1,0};
char orientation[4] ={'o','n','e','s'};
int n,m;
vector<vector<char> > pasture;
int visited [1001][1001];
char g[1001][1001];

bool validPosition(int a, int b){
    if((a<h && a>=0) && (b<w && b>=0))
        return (g[a][b]!='*')?true:false;
    else
        return false;
}

int bfs(pair <int,int> start, pair <int,int> end) {
    queue< pair <char,pair <int,int> > > s;
    pair < char,pair <int,int> >  fir ('q',start);
    s.push(fir);
    visited[start.first][start.second]=0;
    while (s.empty() == false) {
        pair <char,pair <int,int> > top = s.front();
        s.pop();
        //if(end.first == top.second.first && end.second == top.second.second)

        for(int i=0;i<4;i++){
            int newx=top.second.first+positionsX[i],newy=top.second.second+positionsY[i];
            char newp=orientation[i];
            if(validPosition(newx,newy)){
//if(visited->at(top.first)[top.second]+1 < visited->at(newx)[newy]){
                cout<<newp<<" "<<newx<<"-"<<newy<<" "<<visited[newx][newy]<<endl;

                        if(visited[top.second.first][top.second.second]+1 < visited[newx][newy]){
                            if(newp != top.first && top.first != 'q'){
                                visited[newx][newy] = visited[top.second.first][top.second.second]+1;
                            }else{
                                visited[newx][newy] = visited[top.second.first][top.second.second];
                            }
                            pair <int,int> pos(newx,newy);
                            pair <char,pair <int,int> >node (newp,pos);
                            s.push(node);
                        }
            }
        }
     }
     return visited[end.first][end.second];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",&g[i]);
    }
    int sx, sy, ex, ey;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(g[i][j] == 'V')
                    sx = i, sy = j;
                if(g[i][j] == 'H')
                    ex = i, ey = j;
            }
        }

    if(n==1 &&m==1)
        cout<<0;
    else
        cout<<bfs(make_pair(sx,sy),make_pair(ex,ey));
    return 0;

}
