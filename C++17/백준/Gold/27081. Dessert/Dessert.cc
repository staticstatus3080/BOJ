#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int sellect[20]={}, n, cnnt=0;

void DFS(int cnt) {
    if (cnt==n-1) {
        int ans=1, tmp;
        for (int i=0; i<n-1; i++) {
            if (sellect[i]==1) {
                tmp = i+2;
                while (i!=n-2 && sellect[i+1] == 3) {
                    if (i+3>=10) {
                        tmp*=100;
                        i++;
                        tmp += i+2;
                    }
                    else {
                        tmp *= 10;
                        i++;
                        tmp += i+2;
                    }
                }
                ans += tmp;
            }
            else if (sellect[i]==2){
                tmp = i+2;
                while (i!=n-2 && sellect[i+1] == 3) {
                    if (i+3>=10) {
                        tmp*=100;
                        i++;
                        tmp += i+2;
                    }
                    else {
                        tmp *= 10;
                        i++;
                        tmp += i+2;
                    }
                }
                ans -= tmp;
            }
            else {
                ans *= 10;
                ans += i+2;
            }
        }
        if (ans==0) {
            cnnt++;
            if (cnnt<=20) {
                for (int i=0; i<n-1; i++) {
                    cout << i+1 << ' ';
                    if (sellect[i]==1) cout << '+';
                    if (sellect[i]==2) cout << '-';
                    if (sellect[i]==3) cout << '.';
                    cout << ' ';
                }
                cout << n << '\n';
            }
        }
        return;
    }
    for (int i=1; i<=3; i++) {
        sellect[cnt] = i;
        DFS(cnt+1);
    }
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    DFS(0);
    cout << cnnt;
}