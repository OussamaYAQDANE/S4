#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printMatrix(int** mat, int rows = 3, int columns = 3){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int** matrix = new int* [3];
    *matrix = new int[3]{1,2,3};
    *(matrix+1) = new int[3]{4,5,6};
    *(matrix+2) = new int[3]{7,8,9};

    cout <<  "Before inverting:" << endl;
    printMatrix(matrix);
    
    for (int i =0; i < 3; i++) {
        for (int j = 0; j<i;j++){
            matrix[i][j] ^= matrix[j][i];
            matrix[j][i] ^= matrix[i][j];
            matrix[i][j] ^= matrix[j][i];
        }
    }
    
    cout << endl << "After inverting:" << endl;
    printMatrix(matrix);
    
}