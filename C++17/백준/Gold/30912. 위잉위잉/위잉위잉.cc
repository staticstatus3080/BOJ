#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;

vector<pair<ll, ll>> pos;
pair<ll, ll> myPos;

ll Type(pair<ll, ll> p) {
    if (p.X==0 && p.Y>0) return 0;
    else if (p.X<0) return 1;
    else if (p.X==0 && p.Y<0) return 2;
    else return 3;
} 
bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    ll a1 = Type(p1), a2 = Type(p2);
    if (a1==a2) {
        if (a1%2==0) return abs(p1.Y)<abs(p2.Y);
        else {
            long double angle1 = (long double)p1.Y/p1.X, angle2 = (long double)p2.Y/p2.X;
            if (angle1==angle2) {
                return abs(p1.X)+abs(p1.Y)<abs(p2.X)+abs(p2.Y);
            }
            return angle1<angle2;
        }
    }
    return a1<a2;
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (ll i=0; i<n; i++) {
        ll a,b;
        cin >> a >> b;
        pos.push_back({a,b});
    }
    cin >> myPos.X >> myPos.Y;
    for (ll i=0; i<n; i++) {
        pos[i].X -= myPos.X;
        pos[i].Y -= myPos.Y;
    }
    sort(pos.begin(), pos.end(), cmp);
    for (ll i=0; i<n; i++) {
        cout << pos[i].X+myPos.X << ' ' << pos[i].Y+myPos.Y << '\n';
    }
}