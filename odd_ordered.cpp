#include <bits/stdc++.h>
#include <array>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    int magic_square[n][n];
    memset(magic_square, 0, n*n*sizeof(magic_square[0][0]));
    int row = 0;
    int column = n/2;
    int squares = n*n;
    for (int i=1; i<=squares; i++){
        magic_square[row][column] = i;
        if (row == 0 && column != n-1 && magic_square[n-1][column+1]==0){
            row = n-1;
            column++;
        }
        else if (row == 0 && column != n-1 && magic_square[n-1][column+1]>0){
            row++;
        }
        else if (column == n-1 && row != 0 && magic_square[row-1][0]==0){
            row--;
            column = 0;
        }
        else if (column == n-1 && row != 0 && magic_square[row-1][0]>0){
            row++;
        }
        else if (row == 0 && column == n-1){
            row++;
        }
        else if (row>0 && column<n-1 && magic_square[row-1][column+1]==0){
            row--;
            column++;
        }
        else if (row>0 && column<n-1 && magic_square[row-1][column+1]>0){
            row++;
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
