// Find the topological sort of graph

int dfs(int n, int u, vector<bool> &visited, vector<int> &result, vector<vector<int>> &graph) {
    visited[u] = true;
    for(auto next : graph[u]) {
        if(!visited[next]) {
            n = dfs(n, next, visited, result, graph);
        }
    }
    result[n] = u;
    return n-1;
}

vector<int> fun(vector<vector<int>> &graph) {
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