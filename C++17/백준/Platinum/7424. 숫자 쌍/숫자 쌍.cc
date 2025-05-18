#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;
// 7218
// 722528048
int n, len, ans=0;
vector<pair<string, string>> v;
string tmp, x;

bool cmp(pair<string, string> p1, pair<string, string> p2) {
    if (p1.X.length()==p2.X.length()) {
        int len = p1.X.length();
        for (int i=0; i<len; i++) {
            if (p1.X[i]==p2.X[i]) continue;
            return p1.X[i]<p2.X[i];
        }
    }
    return p1.X.length()<p2.X.length();
}
int Calc(string a, string b) {
    int A = stoi(a);
    int B = stoi(b);
    return A+B;
}
void DFS(int cnt, int rem) {
    int obj = rem+tmp[cnt]-'0';
    if (cnt==0) {
        // 그대로
        x.push_back(tmp[cnt]);
        DFS(cnt+1, 0);
        x.pop_back();
        // 올림 고려
        x.push_back(tmp[cnt]-1);
        DFS(cnt+1, 10);
        x.pop_back();
        return;
    }
    if (cnt==len) {
        bool chk=false;
        if (x[0]=='0') {
            if (x.length()==2) return;
            x.erase(x.begin());chk=true;
        }
        int tlen = x.length();
        for (int i=0; i<tlen; i++) {
            string y = x;
            y.erase(y.begin()+i);
            if (Calc(x, y)==n) {
                ans++;
                v.push_back({x,y});
                break;
            }
        }
        if (chk) {x = '0'+x;}
        return;
    }
    for (int i=0; i<=9; i++) {
        if (min(x[cnt-1]-'0', i)+i==(obj-1) || max(x[cnt-1]-'0', i)+i==(obj-1)) {
            x.push_back(i+'0');
            DFS(cnt+1, 10);
            x.pop_back();
        }
        if (min(x[cnt-1]-'0', i)+i==obj || max(x[cnt-1]-'0', i)+i==obj) {
            x.push_back(i+'0');
            DFS(cnt+1, 0);
            x.pop_back();
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    tmp = to_string(n);
    len = tmp.length();
    DFS(0, 0);
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << '\n';
    for (auto it : v) {
        cout << it.X << " + " << it.Y << " = " << n << '\n';
    }
}