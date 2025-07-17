#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

bool con[301][301]={};
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        if (a>b) a^=b^=a^=b;
        con[a][b]=1;
    }
    vector<pair<int, int>> ans;
    if (n<=4) {
        for (int i=1; i<=n-1; i++) {
            for (int j=i+1; j<=n; j++) {
                if (con[i][j]) continue;
                ans.push_back({i,j});
            }
        }
        cout << ans.size() << '\n';
        cout << "1\n";
    }
    else {
        for (int i=2; i<=n; i++) {
            if (con[1][i]) continue;
            ans.push_back({1,i});
        }
        cout << ans.size() << '\n';
        cout << "2\n";
    }
    for (auto cur : ans) {
        cout << cur.X << ' ' << cur.Y << '\n';
    }
}