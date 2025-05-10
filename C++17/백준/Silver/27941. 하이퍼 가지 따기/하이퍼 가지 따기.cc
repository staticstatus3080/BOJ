#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

// 0 : down, 1 : up
vector<int> stat[2048];
int updown[12][2];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    fill(&updown[0][0], &updown[12][0], -1e9);
    for (int i=0; i<2047; i++) {
        for (int j=0; j<11; j++) {
            int a;
            cin >> a;
            stat[i].push_back(a);
            if (updown[j][0] == -1e9) updown[j][0] = stat[i][j];
            else if (updown[j][0] > stat[i][j]) {
                updown[j][1] = updown[j][0];
                updown[j][0] = stat[i][j];
            }
            else if (updown[j][0] < stat[i][j]) updown[j][1] = stat[i][j];
        }
    }
    sort(stat, stat+2047);
    for (int i=0; i<2047; i++) {
        for (int j=0; j<=10; j++) {
            int tmp = i&(1<<(10-j));
            if ((tmp>0 && stat[i][j]==updown[j][0]) || (!tmp && stat[i][j]==updown[j][1])) {
                vector<int> ans;
                for (int j=0; j<=10; j++) {
                    int tmp = i&(1<<(10-j));
                    if (tmp>0) ans.push_back(updown[j][1]);
                    else ans.push_back(updown[j][0]);
                }
                for (auto cur : ans) cout << cur << ' ';
                return 0;
            }
        }
    }
    for (int i=0; i<=10; i++) {
        cout << updown[i][1] << ' ';
    }
}