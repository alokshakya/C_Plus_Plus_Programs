#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<climits>
using namespace std;
int s=0;
struct compare{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second > b.second;
    }
};
vector<int> dijkshtra(vector<list<pair<int,int>>> graph, int e){
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> Q;
    vector<int> distances(graph.size(),INT_MAX);
    vector<bool> visited(graph.size(),false);
    vector<bool> calculated(e,false);
    distances[0] = 0;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        pair<int,int> current = Q.top(); Q.pop();
        cout << "Currently at" << current.first << " current.second "<<current.second<<endl;
        if(!visited[current.first]){
            visited[current.first] = true;
            for(list<pair<int,int>> :: iterator vertex = graph[current.first].begin();vertex != graph[current.first].end();vertex++){
                if(current.second + vertex->second < distances[vertex->first]){
                    distances[vertex->first] = current.second + vertex->second;
                    s=current.second;
                    Q.push(make_pair(vertex->first,distances[vertex->first]));
                }
            }
        }
    }
    return distances;
}
int main(){
    vector<list<pair<int,int>>> graph;
    int v,e,src,des,weight;
    cin >> v >> e;
    graph.resize(v);
    while(e--){
        cin >> src >> des >> weight;
        graph[src-1].push_back(make_pair(des-1,weight));
    }
    vector<int> distances = dijkshtra(graph,e);
    int sum=0;
    for(vector<int> :: iterator itr = distances.begin();itr != distances.end();itr++){
        //cout << *itr << " "<<endl;
        sum+=*itr;
    }
    cout<<"value of s = "<<s<<endl;
    cout<<"value of sum = "<<sum<<endl;
    cout<<"value of sum-s = "<<sum-s<<endl;
    cout<<sum-s<<endl;
    return 0;
}
