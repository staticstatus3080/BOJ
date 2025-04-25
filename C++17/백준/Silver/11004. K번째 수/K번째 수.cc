#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    vector<int> v;
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end());
    cout << v[m-1];
}