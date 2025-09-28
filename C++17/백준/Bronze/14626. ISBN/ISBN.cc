#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int tmp=0;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='*') continue;
        tmp += s[i]-'0';
        if (i%2==1) tmp += (s[i]-'0') *2;
    }
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='*') {
            if (i%2==0) {
                cout << 10-(tmp%10);
                return 0;
            }
            else {
                for (int j=0; j<=9; j++) {
                    int val = j*3;
                    if ((val+tmp)%10==0) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
    cout << s;
}   