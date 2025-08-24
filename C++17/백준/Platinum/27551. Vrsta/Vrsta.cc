#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

ll arr[200001]={}, tree[800001]={};

void Update(int idx, int st, int en, int cur, int diff) {
    if (cur<st || en<cur) return;
    tree[idx] += diff;
    if (st==en) return;
    int mid = (st+en)/2;
    Update(idx*2, st, mid, cur, diff);
    Update(idx*2+1, mid+1, en, cur, diff);
}

int Query(int idx, int st, int en, ll obj) {
    if (st==en) return st;
    int mid = (st+en)/2;
    if (tree[idx*2]<obj) return Query(idx*2+1, mid+1, en, obj-tree[idx*2]);
    return Query(idx*2, st, mid, obj);
}
int n;
vector<pair<int,int>> q;
vector<int> pos;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        q.push_back({a,b});
        pos.push_back(a);
    }
    sort(pos.begin(), pos.end());
    ll sum=0;
    for (auto cur : q) {
        auto [key,num] = cur;
        key = lower_bound(pos.begin(),pos.end(),key) - pos.begin();
        sum += num;
        Update(1, 0, 200000, key, num);
        arr[key]+=num;
        int ans =  Query(1, 0, 200000, (sum+1)/2);
        cout << pos[ans] << '\n';
    }
}