// Bellman-Ford Algorithm to calculate shortest distance from source to all other vertices
// The edges can contain negative weights. Time complexity: O(EV)

class Solution {
    public:
	/*  Function to implement Bellman-Ford Algorithm
    *   adj: vector of vectors which represents the graph
    *   src: source vertex to start traversing graph with
    *   V: number of vertices
    */

    void bellmanFord(int graph[][3], int V, int E, int src) {

        // Initialize distance of all vertices as infinite.
        int dis[V];
        for (int i = 0; i < V; i++)
            dis[i] = INT_MAX;
    
        // initialize distance of source as 0
        dis[src] = 0;
    
        // Relax all edges |V| - 1 times. A simple
        // shortest path from src to any other
        // vertex can have at-most |V| - 1 edges
        for (int i = 0; i < V - 1; i++) {    
            for (int j = 0; j < E; j++) {
                if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
                    dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    
        // check for negative-weight cycles.
        // The above step guarantees shortest
        // distances if graph doesn't contain
        // negative weight cycle.  If we get a
        // shorter path, then there is a cycle.
        for (int i = 0; i < E; i++) {
            int x = graph[i][0];
            int y = graph[i][1];
            int weight = graph[i][2];
            if (dis[x] != INT_MAX && dis[x] + weight < dis[y])
                cout << "Graph contains negative weight cycle"<< endl;
        }
    
        cout << "Vertex Distance from Source" << endl;
        for (int i = 0; i < V; i++)
            cout << i << "\t\t" << dis[i] << endl;
    }
}