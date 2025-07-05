#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

bool isWall[9][9]={};
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1}, dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            char c;
            cin >> c;
            if (c=='#') isWall[i][j]=1;
        }
    }
    queue<pair<int, int>> q;
    q.push({8,1});
    // 후 인생
    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
            auto [x,y] = q.front();
            q.pop();
            for (int i=0; i<9; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if (nx<1 || ny<1 || nx>8 || ny>8) continue;
                if (isWall[nx][ny] || isWall[nx-1][ny]) continue;
                q.push({nx,ny});
                if (nx==1&&ny==8) {
                    cout << 1;
                    return 0;
                }
            }
        }
        for (int i=8; i>=1; i--) {
            for (int j=1; j<=8; j++) {
                if (isWall[i-1][j]==1) isWall[i][j]=1;
                else if (isWall[i][j]) isWall[i][j]=0;
            }
        }
    }
    cout << 0;
}