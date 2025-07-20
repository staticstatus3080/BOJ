#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int arr[7][7], stx, sty;
pair<int, int> p[7][7]={};
bool isnum[7][7]={};
bool vis[7][7]={};
bool flag=0;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int moved[4]={};
void DFS(int x, int y, int z) {
    for (int i=0; i<4; i++) {
        if (p[stx][sty].X!=0) return;
        int nx = x+dx[i], ny = y+dy[i];
        if (nx<1 || ny<1 || nx>6 || ny>6) continue;
        if (!isnum[nx][ny]) continue;
        if (vis[nx][ny]) continue;
        vis[nx][ny]=1;
        moved[i]++;
        if (moved[z]==2 && i==z) {
            if (p[nx][ny].X != 0) flag=1;
            p[stx][sty] = {nx,ny};
            p[nx][ny] = {stx,sty};
            return;
        }
        if (z==-1) DFS(nx,ny, i);
        else DFS(nx, ny, z);
        moved[i]--;
        vis[nx][ny]=0;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=6; j++) {
            cin >> arr[i][j];
            isnum[i][j] = (arr[i][j]>0);
            p[i][j] = {0,0};
        }
    }
    // 전개도 판별
    for (int j=1; j<=6; j++) {
        for (int i=1; i<=6; i++) {
            if (!isnum[i][j]) continue;
            if (p[i][j].X!=0) continue;
            stx=i; sty=j;
            memset(moved, 0, sizeof(moved));
            memset(vis, 0, sizeof(vis));
            vis[i][j]=1;
            DFS(i,j, -1);
            vis[i][j]=0;
            if (p[i][j].X==0 || flag) {
                cout << 0;
                return 0;
            }
        }
    }
    // 정답 구하기
    for (int j=1; j<=6; j++) {
        for (int i=1; i<=6; i++) {
            if (arr[i][j]==1) {
                cout << arr[p[i][j].X][p[i][j].Y];
                return 0;
            }
        }
    }
} 