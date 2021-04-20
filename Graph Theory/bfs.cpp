Breadth First Search

// n = number of nodes
// g = adjacency list representing the unweighted graph
// s = start node, e = end node

vector<int> bfs(int s) {
    queue<int> q;
    q.push(s);
    vector<bool> visited(n, false);
    visited[s] = true;
    vector<int> prev(n, NULL);

    while(!q.isEmpty()) {
        int node = q.front();
        q.pop();
        for(auto next : g[node]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
                prev[next] = node;
            }
        }
    }
    return prev;
}

vector<int> reconstructPath(int s, int e, vector<int> &prev) {
    vector<int> path;
    for(int i=e; i!=NULL; i=prev[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    if(path[0] == s) return path;
    return {};
}

vector<int> traverseBfs(int s, int e) {
    vector<int> prev = bfs(s);
    return reconstructPath(s, e, prev);
}
