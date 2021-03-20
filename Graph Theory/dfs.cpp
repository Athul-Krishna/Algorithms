void dfs(u) {
    if(visited[u]) return;
    visited[u] = 1;

    vector<int> neighbours = g[u];
    for(auto i : neighbours) {
        dfs(i);
    }
}

n = number of nodes
g = adjacency list representing graph
vector<bool> visited(n, false);
dfs(0);