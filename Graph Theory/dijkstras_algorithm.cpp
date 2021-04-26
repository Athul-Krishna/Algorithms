// Dijkstra's Algorithm to calculate shortest distance from source to all other vertices
// The edges should not contain negative weights. Time complexity: O( (E+V) log(V) )

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    typedef pair<int, int> iPair;
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<int> dist(V, INT_MAX);
        pq.push(make_pair(0, S));
        dist[S] = 0;
        
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for(auto x : adj[u]) {
                int v = x[0];
                int w = x[1];
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist;
    }
};