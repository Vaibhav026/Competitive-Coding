// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<bits/stdc++.h>
using namespace std;
# define INF 1000000000000000000
 
std::vector<long long int> tmm[100001];
long long int n,m;

#define fl(i, a, b)     for(long long int i(a); i < (b); i ++)
#define rep(i, n)       fl(i, 0, n)
#define rep1(i, n)      fl(i, 1, n)
#define rfl(i, a, b)    for(long long int i(a); i >= (b); i --)

// iPair ==>  long long Integer Pair
typedef pair<long long int, long long int> iPair;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    long long int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<long long int, long long int> > *adj;
 
public:
    Graph(long long int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(long long int u, long long int v, long long int w);
 
    // prlong long ints shortest path from s
    void shortestPath(long long int s);
};
 
// Allocates memory for adjacency list
Graph::Graph(long long int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(long long int u, long long int v, long long int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
// Prlong long ints shortest paths from src to all other vertices
void Graph::shortestPath(long long int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<long long int> dist(V, INF);
 
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        long long int u = pq.top().second;
        pq.pop();
        
         long long int siz = tmm[u].size();

            long long int temp = dist[u];
            for(long long int j=0;j<siz;j++){

                if(tmm[u][j] > temp)
                    break;
                
                if(tmm[u][j] == temp){
                    temp++;
                }

            }

            long long int delay = temp - dist[u];
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<long long int, long long int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.


            long long int v = (*i).first;
            long long int weight = (*i).second;
 
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight+delay)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight + delay;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 
    // // Prlong long int shortest distances stored in dist[]
    // prlong long intf("Vertex   Distance from Source\n");
    // for (long long int i = 0; i < V; ++i)
    //     prlong long intf("%d \t\t %d\n", i, dist[i]);

    if(dist[n] == INF)
        cout << "-1";
    else
        cout << dist[n];
}


 int main()
{
    

    cin >> n >> m;

    Graph g(n+1);

    long long int a,b,w;

    rep1(i,m+1){

        cin >> a >> b >> w;
        g.addEdge(a,b,w);
    }

     long long int k,x;

    rep1(i,n+1){

        cin >> k;
        for (long long int j = 0; j < k; ++j)
        {
            cin >> x;
            tmm[i].push_back(x);
        }


    }


    g.shortestPath(1);




    return 0;
}