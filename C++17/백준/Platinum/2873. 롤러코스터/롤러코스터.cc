#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;


int arr[1010][1010], m=1e9, dr, dc;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int r, c;
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> arr[i][j];
            if ((i+j)%2==1 && m>arr[i][j]) {
                dr=i, dc=j, m=arr[i][j];
            }
        }
    }
    if (r%2==1) {
        for (int k=0; k<r/2; k++) {
            for (int i=0; i<c-1; i++) {
                cout << 'R';
            }
            cout << 'D';
            for (int i=0; i<c-1; i++) {
                cout << 'L';
            }
            cout << 'D';
        }
        for (int i=0; i<c-1; i++) {
                cout << 'R';
        }
        return 0;
    }
    if (c%2==1) {
        for (int k=0; k<c/2; k++) {
            for (int i=0; i<r-1; i++) {
                cout << 'D';
            }
            cout << 'R';
            for (int i=0; i<r-1; i++) {
                cout << 'U';
            }
            cout << 'R';
        }
        for (int i=0; i<r-1; i++) {
                cout << 'D';
        }
        return 0;
    }
    // dr:y좌표, dc:x좌표
    while (dr>=2 || dc>=2) {
        if (dr>=2) {
            for (int i=0; i<c-1; i++) {
                cout << 'R';
            }
            cout << 'D';
            for (int i=0; i<c-1; i++) {
                cout << 'L';
            }
            cout << 'D';
            dr -= 2;
            r -= 2;
        }
        if (dc>=2) {
            for (int i=0; i<r-1; i++) {
                cout << 'D';
            }
            cout << 'R';
            for (int i=0; i<r-1; i++) {
                cout << 'U';
            }
            cout << 'R';
            dc -= 2;
            c -= 2;
        }
    }
    // 바로 옆 또는 아래에 제거칸
    if (dr==1) {
        cout << "RD";
    }
    else cout << "DR";
    for (int i=0; i<(c-2)/2; i++) {
        cout << "RURD";
    }
    for (int i=0; i<(r-2)/2; i++) {
        cout << 'D';
        for (int j=0; j<c-1; j++) {
            cout << 'L';
        }
        cout << 'D';
        for (int j=0; j<c-1; j++) {
            cout << 'R';
        }
    }
}