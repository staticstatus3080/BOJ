#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;
int chk[21][100005]={}, ans;
vector<int> V;
long long initialize(int N, vector<int> A) {
    for (int i=0; i<N; i++) V.push_back(A[i]);
    ans=N;
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
    if ((p-2*dist)<-1 || (p+2*dist)>V.size()+1) return false;
    return true;
}

void mpropagate(int p, int siz) {
    int t = pow(2, siz+1)-1;
    int dist = (t+1)/2;
    if (lchk(p, dist)) {
        if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
            if (chk[siz+1][p]==0) ans++;
            chk[siz+1][p] = V[p];
        }
        else {
            if (chk[siz+1][p]!=0) ans--;
            chk[siz+1][p]=0;
        }
        mpropagate(p, siz+1);
    }
}
void lpropagate(int p, int siz) {
    int t = pow(2, siz+1)-1; // 산맥 크기
    int dist = (t+1)/2;
    if (lchk(p, dist)) {
        if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
            if (chk[siz+1][p]==0) ans++;
            chk[siz+1][p] = V[p];
        }
        else {
            if (chk[siz+1][p]!=0) ans--;
            chk[siz+1][p]=0;
        }
        lpropagate(p-dist, siz+1);
        mpropagate(p, siz+1);
    }
}
void rpropagate(int p, int siz) {
    int t = pow(2, siz+1)-1; // 산맥 크기
    int dist = (t+1)/2;
    if (lchk(p, dist)) {
        if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
            if (chk[siz+1][p]==0) ans++;
            chk[siz+1][p] = V[p];
        }
        else {
            if (chk[siz+1][p]!=0) ans--;
            chk[siz+1][p]=0;
        }
        rpropagate(p+dist, siz+1);
        mpropagate(p, siz+1);
    }
}
//chk[a][b] : 크기가 a, 중앙이 b인 산맥의 값(산맥 안되면 0)
long long update_sequence(int p, int v) {
    V[p]=v;
    chk[0][p]=v;
    int n = V.size();
    /*
    양옆에 최소산맥부터 propagate
    아마도 중앙 propagate에서 전이되는건 따로해야할듯
    */
    rpropagate(p+1, 0);
    lpropagate(p-1, 0);
    int siz=0;
    /*
    중앙에서 mpropagate하다가 결과가 바뀌면 거기서 mp, lp, rp하고 끝
    */
    bool flag=0;
    while (1) {
        int t = pow(2, siz+1)-1;
        int dist = (t+1)/2;
        if (lchk(p, dist)) {
            if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
                
                if (chk[siz+1][p]==0) {
                    ans++;
                }
                chk[siz+1][p] = V[p];
                rpropagate(p+dist, siz+1);
                lpropagate(p-dist, siz+1);
            }
            else {
                while (chk[siz+1][p]>0) {
                    chk[siz+1][p]=0;
                    ans--;
                    siz++;
                }
                flag=1;
            }
        }
        else break;
        if (flag) break;
        siz++;
    }
    return ans;
}