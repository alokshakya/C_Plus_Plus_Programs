#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <cmath>
#include <queue>
#define MAX_N 105
using namespace std;
const int inf = 1e9 + 5;
int parent[MAX_N];
int n,m,a,b,c,s,d,t;
vector<pair<int,int> > graph[MAX_N];
int dist[MAX_N];
void maxDijkstra(int src)
{
	priority_queue< pair<int,int>, vector<pair<int, int> >, less<pair<int, int> >  > pq;
	pq.push({inf,src});
	dist[src] = inf;
	while(pq.size()){
		pair<int,int> t  = pq.top();
		pq.pop();
		int node = t.second;
		int d = t.first;
		for(int i = 0 ; i < graph[node].size(); i++){
			int v = graph[node][i].first;
			int w = graph[node][i].second;
			int temp = min(w,d);
			if(temp>dist[v]){
				parent[v]=node;
				dist[v]=temp;
				pq.push({temp,v});
			}

		}
	}
}
void printPath(int s, int d){
	if(s==d)
		printf("%d ",d);
	else
	{
		printPath(s,parent[d]);
		printf("%d ",d);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ;i++){
		dist[i]=-1;
		parent[i]=-1;
	}
	for(int i = 0 ;i < m ; i++){
		scanf("%d%d%d",&a,&b,&c);
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	scanf("%d%d%d",&s,&d,&t);
	maxDijkstra(s);
	printPath(s,d);
	int ans = t / (dist[d]-1);
	if(t%(dist[d]-1)!=0){
		ans++;
	}
	printf("\n");
	printf("%d",ans);
	return 0;
}
