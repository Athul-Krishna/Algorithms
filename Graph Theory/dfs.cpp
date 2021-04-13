// Deapth First Search Algorithm

// n = number of nodes
// g = adjacency list representing graph

void dfs(int u) {
    if(visited[u]) return;
    visited[u] = 1;
    
    for(auto i : g[u]) {
        dfs(i);
    }
}

void fun(int n, vector<vector<int>> g) { 
    vector<bool> visited(n, false);
    dfs(0);
}
