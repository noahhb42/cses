#include"bits/stdc++.h"
using namespace std;

bool vis[9][9];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char dir[4] = {'D', 'U', 'R', 'L'};
int ans = 0;

void dfs(int x, int y, int step, const string& s) {

    if (x == 7 && y == 1) {
        if(step == 48){
            ans++;
        }
        return;
    }

    if (step == 48) return;

    if (vis[x-1][y] && vis[x+1][y] && !vis[x][y-1] && !vis[x][y+1]) return;
    if (!vis[x-1][y] && !vis[x+1][y] && vis[x][y-1] && vis[x][y+1]) return;

    for (int k = 0; k < 4; ++k) {
        if(s[step] != '?' && dir[k] != s[step])continue;

        int nx = x + dx[k], ny = y + dy[k];
        if (vis[nx][ny]) continue;

        vis[nx][ny] = true;
        dfs(nx, ny, step + 1, s);
        vis[nx][ny] = false;
    }
}

int main() {
    for (int i = 0; i < 9; ++i) {
        vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = true;
    }

    string s;cin>>s;

    vis[1][1] = true;
    dfs(1, 1, 0, s);

    cout << ans << '\n';
}