#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;
// 사이클 X : 아무 값으로 돌린 뒤 정렬해서 최솟값으로 변환
// 홀수 사이클 존재 && 총합이 짝수 : 하나의 값이 정해짐
// 첫번째 DFS: 홀수 사이클 판별
// 두번째 DFS: 값 하나 잡고 가중치 만들기
ll n, m, dep[100001]={}, node[100001]={}, pinned=-1;
vector<ll> graph[100001], vis;
map<pair<ll, ll>, ll> val;
bool impos=false, cycled=false;

ll getDist(ll a, ll b) {
    if (a>b) swap(a,b);
    return val[{a,b}];
}

void OddCycle(ll st, ll en) {
    vector<ll> cycle;
    reverse(vis.begin(), vis.end());
    for (auto e : vis) {
        cycle.push_back(e);
        if (e==st) break;
    }
    cycle.push_back(en);
    ll siz = cycle.size();
    ll sum=0;
    for (ll i=0; i<siz-1; i++) {
        sum += getDist(cycle[i],cycle[i+1]);
    }
    if (sum&1) {impos=true; return;}
    sum /= 2;
    for (ll i=1; i<siz-1; i+=2) {
        sum -= getDist(cycle[i],cycle[i+1]);
    }
    pinned = cycle[0];
    node[pinned] = sum;
}

void DFS(ll cur, ll pre) {
    for (auto nxt : graph[cur]) {
        if (impos||cycled) return;
        if (nxt==pre) continue;
        if (dep[nxt]!=-1) {
            // 사이클 처리
            ll tmp = abs(dep[nxt]-dep[cur]);
            if (tmp%2==0) {
                OddCycle(nxt, cur);
                cycled=true;
            }
            continue;
        }
        dep[nxt] = dep[cur]+1;
        vis.push_back(nxt);
        DFS(nxt, cur);
        vis.pop_back();
    }
}

void MakeTree(ll cur, ll pre) {
    if (impos) return;
    for (auto nxt : graph[cur]) {
        if (dep[nxt]!=-1) {
            if (getDist(cur, nxt)!=node[cur]+node[nxt]) {
                impos=true;
                return;
            }
            continue;
        }
        dep[nxt] = dep[cur]+1;
        node[nxt] = getDist(cur,nxt)-node[cur];
        MakeTree(nxt, cur);
    }
}

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.Y<p2.Y;
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    ll a, b, c;
    for (ll i=1; i<=m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (a>b) swap(a,b);
        val[{a,b}]=c;
    }
    memset(dep, -1, sizeof(dep));
    dep[1]=0;
    vis.push_back(1);
    DFS(1, 0);
    if (impos) {
        cout << "No";
        return 0;
    }

    memset(dep, -1, sizeof(dep));
    if (pinned!=-1) {
        dep[pinned]=0;
        MakeTree(pinned, 0);
        if (impos) {
            cout << "No";
            return 0;
        }
        cout << "Yes" << '\n';
        for (ll i=1; i<=n; i++) cout << node[i] << ' ';
        return 0;
    }
    dep[1]=0;
    node[1]=0;
    MakeTree(1, 0);
    if (impos) {
        cout << "No";
        return 0;
    }
    vector<pair<ll, ll>> v;
    for (ll i=1; i<=n; i++) {
        if (dep[i]%2==1) node[i] *= -1;
        v.push_back({node[i], i});
    }
    sort(v.begin(), v.end());
    ll siz = v.size();
    ll up = -v[siz/2].X;
    for (ll i=0; i<siz; i++) {
        v[i].X += up;
    }
    sort(v.begin(), v.end(), cmp);
    cout << "Yes" << '\n';
    for (auto e : v) {
        if (dep[e.Y]%2==1) e.X *= -1;
        cout << e.X << ' ';
    }
}