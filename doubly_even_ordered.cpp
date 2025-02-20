#include <bits/stdc++.h>
#include <array>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    int magic_square[n][n];
    int d1 = n/4;
    memset(magic_square, 0, n*n*sizeof(magic_square[0][0]));
    
    for (int i=0; i<d1; i++){
        for (int j=d1; j<(n-d1); j++){
            magic_square[i][j] = i*n + j +1;
        }
    }
    for (int i=d1; i<(n-d1); i++){
        for (int j=0; j<d1; j++){
            magic_square[i][j] = i*n + j +1;
        }
    }
    for (int i=d1; i<(n-d1); i++){
        for (int j=(n-d1); j<n; j++){
            magic_square[i][j] = i*n + j +1;
        }
    }
    for (int i=(n-d1); i<n; i++){
        for (int j=d1; j<(n-d1); j++){
            magic_square[i][j] = i*n + j +1;
        }
    }
    int var = 64;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (magic_square[i][j] == 0){
                magic_square[i][j] = var;
            }
            var--;
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << magic_square[i][j] << "    ";
        }
        cout << "\n" << endl;
    }
    
    return 0;
}