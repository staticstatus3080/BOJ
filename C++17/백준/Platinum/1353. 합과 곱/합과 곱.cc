#include <bits/stdc++.h>

using namespace std;

int main() {
    long double a, b;
    cin >> a >> b;
    int i=1;
    if (a <= b) do {
        long double tmp = 1;
        for (int j=0; j<i; j++) tmp *= a/i;
        if (tmp >= b) {cout << i; return 0;}
        i++;
    } while (a/i >= 1);
    else {
        cout << 2;
        return 0;
    }
    cout << -1;
}