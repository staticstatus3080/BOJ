#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

multiset<ll> s[200003], tmax, maxs;
ll sum=0;
vector<pii> v;
void Calc() {
    ll tmaxe = tmax.size() ? *(tmax.rbegin()) : 0;
    ll diff = max((ll)0, (ll)(tmaxe-*maxs.begin()));
    cout << sum+diff << '\n';
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    v.push_back({0,0});
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        s[a].insert(b);
    }
    for (int i=1; i<=m; i++) {
        auto it = s[i].rbegin();
        sum += *it;
        maxs.insert(*it);
        if (s[i].size()<=1) continue;
        it++; 
        tmax.insert(*it);
    }
    Calc();
    while (q--) {
        ll a, b, c;   
        cin >> a >> b >> c;
        if (a==1) {
            //b번째 업보의 종류를 c로 바꿈
            auto it = s[v[b].X].rbegin();
            maxs.erase(maxs.find(*it));
            sum -= *it;
            if (s[v[b].X].size()>=2) {
                it++;
                tmax.erase(tmax.find(*it));
                it--;
            }
            s[v[b].X].erase(s[v[b].X].find(v[b].Y));
            it = s[v[b].X].rbegin();
            maxs.insert(*it);
            sum += *it;
            if (s[v[b].X].size()>=2) {
                it++;
                tmax.insert(*it);
            }
            v[b].X = c;
            it = s[v[b].X].rbegin();
            maxs.erase(maxs.find(*it));
            sum -= *it;
            if (s[v[b].X].size()>=2) {
                it++;
                tmax.erase(tmax.find(*it));
                it--;
            }
            s[v[b].X].insert(v[b].Y);
            it = s[v[b].X].rbegin(); 
            maxs.insert(*it);
            sum += *it;
            if (s[v[b].X].size()>=2) {
                it++;
                tmax.insert(*it);
            }
        }
        else {
            // b번째 업보를 c로 바꿈
            // maxs, tmax 에서 빼 그리고 다시 집어넣어
            auto it =  s[v[b].X].rbegin();
            maxs.erase(maxs.find(*it));
            sum -= *it;
            if (s[v[b].X].size()>=2) {
                it++;
                tmax.erase(tmax.find(*it));
                it--;
            }
            s[v[b].X].erase(s[v[b].X].find(v[b].Y));
            v[b].Y = c;
            s[v[b].X].insert(c);
            it = s[v[b].X].rbegin();
            maxs.insert(*it);
            sum += *it;
            if (s[v[b].X].size()>=2) {
                it++;
                tmax.insert(*it);
            }
        }
        Calc();
    }
}    