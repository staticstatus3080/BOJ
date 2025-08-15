#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;

int arr[200002];
bool vis[200002]={};
vector<int> l, r;
multiset<int> s;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=0; i<2*m; i++) {
        int a;
        cin >> a;
        if (i<m) l.push_back(a);
        else r.push_back(a);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    bool flag=0;
    int en=0;
    for (int i=0; i<m; i++) {
        if (l[i]>r[i]) flag=1;
        if (flag) break;
        for (int j=max(l[i],en); j<=r[i]; j++) vis[j]=1;
        en = max(en, r[i]);
    }
    for (int i=1; i<=n; i++) {
        if (vis[i]) s.insert(arr[i]);
    }
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        if (flag) {
            cout << (int)1e9 << '\n';
            continue;
        }
        if (a!=b&&vis[a]) {s.erase(s.find(arr[a])); s.insert(arr[b]);}
        if (a!=b&&vis[b]) {s.erase(s.find(arr[b])); s.insert(arr[a]);}
        swap(arr[a], arr[b]);
        cout << *(s.rbegin()) << '\n';
    }
}   