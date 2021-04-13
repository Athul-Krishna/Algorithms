// Find all connected components in a graph using dfs

// n = number of nodes
// g = adjacency list representing graph
// components = empty integer array of size n
int count = 0;
vector<bool> visited(n, false);

void dfs(int u) {
    visited[u] = 1;
    components[u] = count;

    for(auto i : g[u]) {
        if(!visied[i]) dfs(i);
    }
}

function findComponents() {
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            count++;
            dfs(i);
        }
    }
    return (count, components);
}
