#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int n, arr[1001], pos[1001];
vector<pair<int, int>> output;
pair<int, int> GetBound(int st, int en) {
    if (st>en) swap(st,en);
    while (st!=en) {
        if (arr[st]!=st) break;
        st++;
    }
    while (st!=en) {
        if (arr[en]!=en) break;
        en--;
    }
    return {st,en};
}
void Swap(int st, int en) {
    if (st>en) swap(st,en);
    while (st<en) {
        swap(arr[st], arr[en]);
        st++; en--;
    }
}
void SwapPos(int st, int en) {
    if (st>en) swap(st,en);
    while (st<en) {
        swap(pos[st], pos[en]);
        st++; en--;
    }
}
bool CheckOne(int st, int en) {
    if (st>en) swap(st,en);
    auto [s,e] = GetBound(st,en);
    while (s<=e) {
        if (arr[s]!=e || arr[e]!=s) return false;
        s++; e--;
    }
    return true;
}
bool CheckSecond(int s, int e) {
    auto [st,en] = GetBound(s,e);
    for (int i=st; i<=en; i++) pos[arr[i]] = i;
    Swap(st, pos[st]);
    if (CheckOne(st,en)) {
        int tmp = pos[st];
        if (st>tmp) swap(st, tmp);
        output.push_back({st,tmp});
        auto [ans1,ans2] = GetBound(1,n);
        output.push_back({ans1,ans2});
        return true;
    }
    else {
        Swap(st, pos[st]);
        Swap(en, pos[en]);
        if (!CheckOne(st, en)) {
            Swap(en, pos[en]);
            return false;
        }
        int tmp = pos[en];
        if (en>tmp) swap(en, tmp);
        output.push_back({en,tmp});
        auto [ans1,ans2] = GetBound(1,n);
        output.push_back({ans1,ans2});
        return true;
    }
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++) {cin >> arr[i]; pos[arr[i]]=i;}
    auto [st,en] = GetBound(1,n);
    for (int i=st; i<en; i++) {
        for (int j=i+1; j<=en; j++) {
            Swap(i,j);
            if (CheckSecond(st,en)) {
                cout << i << ' ' << j << '\n';
                for (auto cur : output) {
                    cout << cur.X << ' ' << cur.Y << '\n';
                }
                return 0;
            }
            Swap(i,j);
        }
    }
    for (int i=1; i<=3; i++) {
        cout << "1 1\n";
    }
} 