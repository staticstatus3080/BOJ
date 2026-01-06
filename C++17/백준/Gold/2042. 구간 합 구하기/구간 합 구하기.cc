#include <bits/stdc++.h>
#define ll long long
// https://yabmoons.tistory.com/431의 설명을 참고하였습니다.
using namespace std;
ll arr[1000001], segment_tree[4000001];

ll make_tree(int idx, int start, int end) {
    if (start == end) return segment_tree[idx] = arr[start];
    ll result=0, mid = (start+end)/2;
    result += make_tree(idx*2, start, mid);
    result += make_tree(idx*2+1, mid+1, end);
    return segment_tree[idx] = result;
}

void update(int idx, int start, int end, int changeIdx, ll dif) {
    if (changeIdx < start || end < changeIdx) return;
    segment_tree[idx] += dif;
    int mid = (start+end)/2;
    if (start == end) return;
    update(idx*2, start, mid, changeIdx, dif);
    update(idx*2+1, mid+1, end, changeIdx, dif);
}

ll sum(int idx, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return segment_tree[idx];
    ll result=0, mid = (start+end)/2;
    result += sum(idx*2, start, mid, left, right);
    result += sum(idx*2+1, mid+1, end, left, right);
    return result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) cin >> arr[i];
    make_tree(1, 0, n-1);
    for (int i=0; i<m+k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) { // update
            update(1, 0, n-1, b-1, c-arr[b-1]);
            arr[b-1] = c;
        }
        else { // sum
            cout << sum(1, 0, n-1, b-1, c-1) << '\n';
        }
    }
}