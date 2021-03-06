// C++ program to print all paths from a source to destination.
#include<bits/stdc++.h>
#include <list>
#include<vector>

using namespace std;
vector<int> alok;
// A directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);

public:
    Graph(int V);   // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u�s list.
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d )
{
    vector<int> vec;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    alok.clear();
    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]

    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
        {
            //cout<<path[i]<<endl;
            alok.push_back(path[i]);
        }

    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

// Driver program
int main()
{

    // Create a graph given in the above diagram
    int n,m,i,a,b,c;

    cin>>n>>m;
    Graph g(n);
    vector<int> gangs(n);
    //vector<int> adj[n];
    for(i=0;i<n;i++)
    {
        cin>>a;
        gangs[i]=a;
    }
    for(i=0;i<(n-1);i++)
    {
        cin>>b>>c;
        b--;c--;
        g.addEdge(b, c);
        g.addEdge(c, b);

    }
for(i=0;i<m;i++)
    {
        cin>>b>>c;
        b--;c--;
        alok.clear();
        g.printAllPaths(b, c);
        map<int,int> mymap;
         vector<int>::iterator it;

         for(it=alok.begin();it!=alok.end();it++)
         {
             //cout<<"    "<<*it<<" value = "<<gangs[(*it)]<<"    ";
             if(mymap.find(gangs[(*it)])!=mymap.end())
                mymap[gangs[(*it)]]=mymap[gangs[(*it)]]+1;
             else
                mymap[gangs[(*it)]]=1;

         }
         map<int,int>::iterator mapIt;
         int sz=alok.size();
         //cout<<"size of path "<<sz<<endl;
        // cout<<"value should be "<<(double)(sz/2)<<endl;
         int flag=0;
         for(mapIt=mymap.begin();mapIt!=mymap.end();mapIt++)
         {
            // int v=(it->second)/sz;
            //cout<<(*mapIt).first<<"  times "<<(*mapIt).second<<endl;
            if((*mapIt).second>(sz/2))
            {
                cout<<"D "<<(*mapIt).first<<endl;
                flag=1;
            }


         }
         if(flag==0)
            cout<<"S"<<endl;

            //cout<<"max element "<<max<<" at index "<<in<<endl;


    }




    return 0;
}
