// Find the size of the Shortest Path to reach exit in a grid using BFS algorithm

// R, C = number of rows and number of columns
// m = Input matrix of size RxC with 'E' as destination and '#' as blocked cells
// sr, sc = row and column of starting point

// Variables to track number of steps taken
int moves = 0;
int nodes_left_in_layer = 1;
int nodes_in_next_layer = 0;
bool reached_end = false;

// Direction vectors (here movement only up, down, left, right)
vector<int> dr = { -1, +1, 0, 0 };
vector<int> dc = { 0, 0, +1, -1 };

queue<int> rq;
queue<int> cq;
vector<vector<bool>> visited(R, vector<bool> (C, false));

void explore_neighbours(int r, int c) {
    for(int i=0; i<4; i++) {
        rr = r + dr[i];
        cc = c + dc[i];

        if(rr < 0 || cc < 0) continue;
        if(rr >= R || cc >= C) continue;

        if(visited[rr][cc]) continue;
        if(m[rr][cc] == '#') continue;

        rq.push(rr);
        cq.push(cc);
        visited[rr][cc] = true;
        nodes_in_next_layer++;
    }
}

int bfsShortestPath() {
    rq.push(sr); cq.push(sc);
    visited[sr][sc] = true;
    while(!rq.isEmpty()) {
        int r = rq.front(); rq.pop();
        int c = cq.front(); cq.pop();
        if(m[r][c] == 'E') {
            reached_end = true;
            break;
        }
        explore_neighbours(r, c);
        nodes_left_in_layer--;
        if(nodes_left_in_layer == 0) {
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            moves++;
        }
    }
    if(reached_end) return moves;
    return -1;
}