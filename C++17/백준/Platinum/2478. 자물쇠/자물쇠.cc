#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int arr[2][501],n;
void Move(int idx, int dir) {
    int tmp[501];
    dir *= -1;
    for (int i=1; i<=n; i++) {
        int nxt = i+dir;
        if (nxt<=0)nxt+=n;
        if (nxt>n) nxt-=n;
        tmp[nxt]=arr[idx][i];
    }
    for (int i=1; i<=n; i++) arr[idx][i] = tmp[i];
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[1][i];
        arr[0][i]=i;
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            Move(0, i);
            Move(1, -j);
            int a=1, b=n;
            while (arr[0][a]==arr[1][a] && a<=n) a++;
            while (arr[0][b]==arr[1][b] && b>=1) b--;
            if (a<=b) {
                for (int k=a; k<=b; k++) {
                    if (arr[0][k]!=arr[1][a+b-k]) break;
                    if (k!=b) continue;
                    cout << i << '\n';
                    cout << a << ' ' << b << '\n';
                    cout << j << '\n';
                    return 0;
                }
            }
            Move(0, -i);
            Move(1, j);
        }
    }
}