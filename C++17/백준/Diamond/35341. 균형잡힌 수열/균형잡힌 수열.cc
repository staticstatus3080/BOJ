#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;
int chk[21][100005]={}, ans, nn, pp[21]={};
// -크기, 위치, 함수명, (필요시) cnt
// -1:lp, 0:mp, 1:rp
deque<tuple<int,int,int,int>> pq;
vector<int> V;
long long initialize(int N, vector<int> A) {
    pp[1]=2;
    for (int i=2; i<=20; i++) pp[i]=pp[i-1]*2;
    for (int i=0; i<N; i++) V.push_back(A[i]);
    ans=N;
    nn=N;
    for (int i=0; i<N; i++) {
        chk[0][i] = A[i];
    }
    int t=0;
    for (int j=1; j<=20; j++) {
        t = t*2+1;
        int dist = (t+1)/2;
        for (int i=t; i<N-t; i++) {
            if (chk[j-1][i-dist]>0 && chk[j-1][i+dist]>0 && max(chk[j-1][i-dist],chk[j-1][i+dist])<A[i]) {
                chk[j][i] = A[i];
                ans++;
            }
        }
    }
    return ans;
}
bool lchk(int p, int dist) {
    if ((p-2*dist)<-1 || (p+2*dist)>nn+1) return false;
    return true;
}

void rp(int p, int siz, int cnt) {
    int t = pp[siz+1]-1;
    int dist = (t+1)/2;
    bool flag=0;
    if (lchk(p, dist)) {
        if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
            if (chk[siz+1][p]==0) {ans++; cnt++; flag=1;}
            chk[siz+1][p] = V[p];
        }
        else {
            if (chk[siz+1][p]!=0) {ans--; chk[siz+1][p]=0; cnt++; flag=1;}
        }
        pq.push_back({siz+1, p, 1, cnt});
    }
    if (cnt==0) return;
    if (!flag) pq.push_front({siz, p+dist, 1, 0});
}

void lp(int p, int siz, int cnt) {
    int t = pp[siz+1]-1;
    int dist = (t+1)/2;
    bool flag=0;
    if (lchk(p, dist)) {
        if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
            if (chk[siz+1][p]==0) {ans++; cnt++; flag=1;}
            chk[siz+1][p] = V[p];
        }
        else {
            if (chk[siz+1][p]!=0) {ans--; chk[siz+1][p]=0; cnt++; flag=1;}
        }
        pq.push_back({siz+1, p, -1, cnt});
    }
    if (cnt==0) return;
    if (!flag) pq.push_front({siz, p-dist, -1, 0});
}

void mpropagate(int p, int siz) {
    int t = pp[siz+1]-1;
    int dist = (t+1)/2;
    bool flag=0;
    if (lchk(p, dist)) {
        if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
            if (chk[siz+1][p]==0) ans++;
            else flag=1;
            chk[siz+1][p] = V[p];
        }
        else {
            if (chk[siz+1][p]!=0) ans--;
            else flag=1;
            chk[siz+1][p]=0;
        }
        // 중앙 결과가 달라지다가 같아짐
        if (flag) {
            pq.push_front({siz, p-dist, -1, 0});
            pq.push_front({siz, p+dist, 1, 0});
            return;
        }
        pq.push_back({(siz+1), p, 0, 0});
        return;
    }
    else {
        pq.push_front({siz, p-dist, -1, 0});
        pq.push_front({siz, p+dist, 1, 0});
    }
    
}
long long update_sequence(int p, int v) {
    V[p]=v;
    chk[0][p]=v;
    int n = V.size();
    int siz=0;
    bool flag=0;
    
    while (1) {
        int t = pow(2, siz+1)-1;
        int dist = (t+1)/2;
        if (lchk(p, dist)) {
            if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
                if (chk[siz+1][p]==0) {
                    ans++;
                    flag=1;
                }
                chk[siz+1][p] = V[p];
            }
            else {
                if (chk[siz+1][p]>0) {
                    ans--;
                    chk[siz+1][p] = 0;
                    flag=1;
                }
                else {
                    pq.push_front({siz, p-dist, -1, 0});
                    pq.push_front({siz, p+dist, 1, 0});
                    break;
                }
            }
        }
        else {
            pq.push_front({siz, p-dist, -1, 0});
            pq.push_front({siz, p+dist, 1, 0});
            break;
        }
        if (flag) {
            pq.push_back({siz+1, p, 0, 0});
            pq.push_front({siz, p-dist, -1, 0});
            pq.push_front({siz, p+dist, 1, 0});
            break;
        }
        siz++;
    }
    // 중앙에 산맥이 생김과 동시에 다른쪽에서 끊어질 수 있음
    int a, b, c, d;
    while (!pq.empty()) {
        auto [a, b, c, d] = pq.front();
        pq.pop_front();
        if (c==0) mpropagate(b, a);
        if (c==-1) lp(b, a, d);
        if (c==1) rp(b, a, d); 
    }
    
    return ans;
}
