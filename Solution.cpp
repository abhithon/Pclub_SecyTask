#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int shortest_path(vector<string>& s, int sx, int sy, int gx, int gy) {
    int m = s.size();
    int n = s[0].size();
    vector<vector<bool>> used(m, vector<bool>(n, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});

    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if (used[cy][cx]) continue;
        if (cx == gx && cy == gy) return dist;
        used[cy][cx] = true;
        rep(i, 4) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (s[ny][nx] == '#') continue;
            q.push({{nx, ny}, dist + 1});
        }
    }
    return -1;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> s(m);
    rep(i, m) cin >> s[i];
    int res = -1;
    rep(sy, m) rep(sx, n) {
        rep(gy, m) rep(gx, n) {
            if (s[sy][sx] == '#' || s[gy][gx] == '#') continue;
            int dist = shortest_path(s, sx, sy, gx, gy);
            res = max(res, dist);
        }
    }
    cout << res << endl;
    return 0;
}
