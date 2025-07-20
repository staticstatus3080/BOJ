#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int n, arr[10001], pos[10001];

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
    return;
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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++) {cin >> arr[i]; pos[arr[i]]=i;}
    auto [st, en] = GetBound(1,n);
    Swap(st, pos[st]);
    if (CheckOne(st,en)) {
        int tmp = pos[st];
        if (st>tmp) swap(st, tmp);
        cout << st << ' ' << tmp << '\n';
        auto [ans1,ans2] = GetBound(1,n);
        cout << ans1 << ' ' << ans2 << '\n';
        return 0;
    }
    else {
        Swap(st, pos[st]);
        Swap(en, pos[en]);
        int tmp = pos[en];
        if (en>tmp) swap(en, tmp);
        cout << en << ' ' << tmp << '\n';
        auto [ans1,ans2] = GetBound(1,n);
        cout << ans1 << ' ' << ans2 << '\n';
    }
} 