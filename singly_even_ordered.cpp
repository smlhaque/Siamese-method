#include <bits/stdc++.h>
#include <array>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    int magic_square[n][n];
    int k = n/2;
    int smaller_gridA[k][k], smaller_gridB[k][k], smaller_gridC[k][k], smaller_gridD[k][k];
    
    
    int squares_per_grid = k*k;
    
    memset(smaller_gridA, 0, squares_per_grid*sizeof(magic_square[0][0]));
    memset(smaller_gridB, 0, squares_per_grid*sizeof(magic_square[0][0]));
    memset(smaller_gridC, 0, squares_per_grid*sizeof(magic_square[0][0]));
    memset(smaller_gridD, 0, squares_per_grid*sizeof(magic_square[0][0]));
    
    int row = 0;
    int column = k/2;
    for (int i=1; i<=squares_per_grid; i++){
        smaller_gridA[row][column] = i;
        smaller_gridB[row][column] = i + squares_per_grid;
        smaller_gridC[row][column] = i + 2*squares_per_grid;
        smaller_gridD[row][column] = i + 3*squares_per_grid;
        if (row == 0 && column != k-1 && smaller_gridA[k-1][column+1]==0){
            row = k-1;
            column++;
        }
        else if (row == 0 && column != k-1 && smaller_gridA[k-1][column+1]>0){
            row++;
        }
        else if (column == k-1 && row != 0 && smaller_gridA[row-1][0]==0){
            row--;
            column = 0;
        }
        else if (column == k-1 && row != 0 && smaller_gridA[row-1][0]>0){
            row++;
        }
        else if (row == 0 && column == k-1){
            row++;
        }
        else if (row>0 && column<k-1 && smaller_gridA[row-1][column+1]==0){
            row--;
            column++;
        }
        else if (row>0 && column<k-1 && smaller_gridA[row-1][column+1]>0){
            row++;
        }
    }
    
    int local_var1;
    int local_var2;
    int local_var3;
    int local_var4;
    int exchange = k/2;
    for (int i=0; i<k; i++){
        for (int j=0; j<exchange; j++){
            local_var1 = smaller_gridA[i][j];
            smaller_gridA[i][j] = smaller_gridD[i][j];
            smaller_gridD[i][j] = local_var1;
        }
    }
    for (int i=0; i<k; i++){
        for (int j=k-1; j>(k-exchange); j--){
        local_var2 = smaller_gridC[k-1-i][j];
        smaller_gridC[k-1-i][j] = smaller_gridB[k-1-i][j];
        smaller_gridB[k-1-i][j] = local_var2;
        }
    }
    local_var3 = smaller_gridA[k/2+1][0];
    smaller_gridA[k/2+1][0] = smaller_gridD[k/2+1][0];
    smaller_gridD[k/2+1][0] = local_var3;
    
    local_var4 = smaller_gridA[k/2+1][k/2+1];
    smaller_gridA[k/2+1][k/2+1] = smaller_gridD[k/2+1][k/2+1];
    smaller_gridD[k/2+1][k/2+1] = local_var4;
    
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            magic_square[i][j] = smaller_gridA[i][j];
            magic_square[i][k+j] = smaller_gridC[i][j];
            magic_square[k+i][j] = smaller_gridD[i][j];
            magic_square[k+i][k+j] = smaller_gridB[i][j];
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
