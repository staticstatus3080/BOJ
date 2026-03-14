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

/*
가운데에서 시작하는 전파는 chk가 끝날때 시작 (물론 배열 변화 없으면 안해도됨)
경우 1(chk배열이 더 채워짐) : chk배열이 채워진 마지막 크기부터 전파
경우 2(chk배열이 덜 채워짐) : 원래 chk배열이 채워진 마지막 크기부터 전파
한마디로 chk배열이 달라지면 달라진 마지막 크기부터 전파
*/

void rp(int p, int siz, int cnt) {
    int t = pow(2, siz+1)-1;
    int dist = (t+1)/2;
    bool flag=0;
    if (lchk(p, dist)) {
        if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
            if (chk[siz+1][p]==0) {ans++; chk[siz+1][p] = V[p];}
            else if (cnt==0)return;
            else {
                rp(p+dist, siz, 0);
            }
        }
        else {
            if (chk[siz+1][p]!=0) {ans--; chk[siz+1][p]=0;}
            else if (cnt==0) return;
            else {
                rp(p+dist, siz, 0);
            }
        }
        rp(p, siz+1, cnt+1);
    }
    if (cnt==0) return;
    rp(p+dist, siz, 0);
}

void lp(int p, int siz, int cnt) {
    int t = pow(2, siz+1)-1;
    int dist = (t+1)/2;
    bool flag=0;
    if (lchk(p, dist)) {
        if (chk[siz][p-dist]>0 && chk[siz][p+dist]>0 && max(chk[siz][p-dist],chk[siz][p+dist])<V[p]) {
            if (chk[siz+1][p]==0) {ans++; chk[siz+1][p] = V[p];}
            else if (cnt==0)return;
            else {
                lp(p-dist, siz, 0);
            }
        }
        else {
            if (chk[siz+1][p]!=0) {ans--; chk[siz+1][p]=0;}
            else if (cnt==0) return;
            else {
                lp(p-dist, siz, 0);
            }
        }
        lp(p, siz+1, cnt+1);
    }
    if (cnt==0) return;
    lp(p-dist, siz, 0);
}
void mpropagate(int p, int siz) {
    int t = pow(2, siz+1)-1;
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
        if (flag) {
            lp(p-dist, siz, 0);
            rp(p+dist, siz, 0);
            return;
        }
        mpropagate(p, siz+1);
        return;
    }
    lp(p-dist, siz, 0);
    rp(p+dist, siz, 0);
}
long long update_sequence(int p, int v) {
    V[p]=v;
    chk[0][p]=v;
    int n = V.size();
    /*
    양옆에 최소산맥부터 propagate
    아마도 중앙 propagate에서 전이되는건 따로해야할듯
    */
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
                    lp(p-dist, siz, 0);
                    rp(p+dist, siz, 0);
                    break;
                }
            }
        }
        else {
            lp(p-dist, siz, 0);
            rp(p+dist, siz, 0);
            break;
        }
        if (flag) {
            mpropagate(p, siz+1);
            break;
        }
        siz++;
    }
    mpropagate(p+1, 0);
    mpropagate(p-1, 0);
    return ans;
}
