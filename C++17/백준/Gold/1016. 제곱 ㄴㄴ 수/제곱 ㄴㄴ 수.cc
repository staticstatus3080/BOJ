#include <bits/stdc++.h>
// 다음 글의 댓글을 참고하였습니다. https://www.acmicpc.net/board/view/142017
using namespace std;

vector<long long> square;
int notPrime[1000001] = {};

void SquareSieve() {
    square.push_back(4);
    for (long long i=3; i<=1000000; i+=2) {
        if (notPrime[i]) continue;
        square.push_back(i*i);
        for (long long j=i*i; j<=1000000; j+=i) {
            notPrime[j] = 1;
        }
    }
}


int main() {
    long long minn, maxx;
    SquareSieve();
    cin >> minn >> maxx;
    int ans = maxx - minn + 1;
    map<long long, int> m;
    for (long long i : square) {
        if (i > maxx) break;
        long long j = minn/i;
        while (j*i<=maxx) {
            if (j*i >= minn && m[j*i] != 1) {ans--; m[j*i]++;}
            j++;
        }
    }
    
    cout << ans;
}