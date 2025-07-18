#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> v;
vector<int> LIS;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.X==p2.X) return p1.Y<p2.Y;
    return p1.X>p2.X;
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, a, b, c;;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c;
        v.push_back({b,c});
    }
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto [trash,cur] : v) {
        if (LIS.empty() || LIS[LIS.size()-1]<=cur) {LIS.push_back(cur); continue;}
        int idx = upper_bound(LIS.begin(), LIS.end(), cur) - LIS.begin();
        LIS[idx]=cur;
    }
    cout << LIS.size();
} 