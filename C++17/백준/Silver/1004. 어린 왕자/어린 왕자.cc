#include <iostream>
#include <cmath>

using namespace std;

bool isIn(int x1, int y1, int x2, int y2, int r) {
    return pow((x1-x2), 2) + pow((y1-y2), 2) < r*r ? 1 : 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        pair<int, int> s, e;
        cin >> s.first >> s.second >> e.first >> e.second;
        int circles, ans=0;
        cin >> circles;
        
        while (circles--) {
            int a, b, r;
            cin >> a >> b >> r;
            bool isStartIn = isIn(s.first, s.second, a, b, r);
            bool isEndIn = isIn(e.first, e.second, a, b, r);
            
            if (!isStartIn && !isEndIn) continue; // 원이 두 점 바깥에 있음
            if (isStartIn && isEndIn) continue; // 원이 두 점을 포함함
            ans++;
        }
        cout << ans << '\n';
    }
}