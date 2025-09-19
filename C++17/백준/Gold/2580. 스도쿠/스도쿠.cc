#include <iostream>

using namespace std;

int map[10][10];
bool check[10][10][10] = {0,}; // check : 좌표 i, j에 1~9까지의 숫자 배치 가능여부
bool isSuccess = false;

void hCheck(int I, int J) {
    for (int i=0; i<9; i++) {
        check[I][J][map[i][J]] = 1;
    }
}
void vCheck(int I, int J) {
    for (int j=0; j<9; j++) {
        check[I][J][map[I][j]] = 1;
    }
}

void cellCheck(int I, int J) {
    int tI = I/3, tJ = J/3;
    
    for (int i=tI*3; i/3 == tI; i++) {
        for (int j=tJ*3; j/3 == tJ; j++) {
            check[I][J][map[i][j]] = 1; 
        }
    }
}

void DFS(int cur, int max) {
    if (cur == max) {
        isSuccess = true;
        return;
    }
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (map[i][j] != 0) continue;
            
            for (int k=1; k<=9; k++) {check[i][j][k] = 0;} // Init
            hCheck(i, j);
            vCheck(i, j);
            cellCheck(i, j);
            
            for (int k=1; k<=9; k++) {
                if (check[i][j][k] != 0) continue;
                map[i][j] = k;
                
                DFS(cur+1, max);
                
                if (isSuccess) return;
            }
            map[i][j] = 0;
            return;
        }
    }
}

int main() {
    
    int zeroCnt = 0;
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {zeroCnt++;}
        }
    }
    
    DFS(0, zeroCnt);
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}