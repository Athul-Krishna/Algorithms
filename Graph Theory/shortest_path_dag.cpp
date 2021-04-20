// Program to find the shortest path from start node
// to all other nodes in a Directed Acyclic Graph

int dfs(int n, int u, vector<bool> &visited, vector<int> &result, vector<vector<int>> &graph) {
    visited[u] = true;
    for(auto next : graph[u]) {
        if(!visited[next[0]]) {
            n = dfs(n, next[0], visited, result, graph);
        }
    }
    result[n] = u;
    return n-1;
}

vector<int> topologicalSort(vector<vector<int>> &graph) {
    N = graph.size();
    vector<bool> visited(N, false);
    vector<int> result(N, 0);
    int n = N-1;

    for(int i=0; i<N; i++) {
        if(!visited[i]) {
            n = dfs(n, i, visited, result, graph);
        }
    }
    return result;
}

// graph is the adjacency list where graph[0] = { pair<to, weight>, pair<to, weight>, ... }
vector<int> dagShortestPath(vector<vector<int>> &graph, int start, int numNodes) {
    vector<int> topsort = topologicalSort(graph);
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    for(int i=0; i<numNodes; i++) {
        int nodeIndex = topsort[i];
        if(dist[nodeIndex] != NULL) {
            for(auto next : graph[nodeIndex]) {
                int newDist = dist[nodeIndex] + next[1]];
                if(dist[next[0]] == null) dist[next[0]] = newDist;
                else dist[next[0]] = min(dist[next[0]], newDist);
            }
        }
    }
    return dist;
}