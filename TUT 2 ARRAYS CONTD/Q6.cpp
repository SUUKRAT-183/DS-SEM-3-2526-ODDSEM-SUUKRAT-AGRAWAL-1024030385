#include <iostream>
using namespace std;

#define MAX 100

void readSparse(int mat[MAX][3]) {
    int r, c, n;
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> r >> c >> n;

    mat[0][0] = r;
    mat[0][1] = c;
    mat[0][2] = n;

    for (int i = 1; i <= n; i++) {
        cout<<"Enter row value for non zero element number "<<i;
        cin >> mat[i][0];
        cout<<"Enter column value for non zero element number "<<i;
        cin >> mat[i][1];
        cout<<"Enter non zero value for non zero element number "<<i;
        cin >> mat[i][2];
         
    }
}

void printSparse(int mat[MAX][3]) {
    int n = mat[0][2];
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i <= n; i++) {
        cout << mat[i][0] << "\t" << mat[i][1] << "\t" << mat[i][2] << "\n";
    }
}

void transpose(int mat[MAX][3], int trans[MAX][3]) {
    int r = mat[0][0], c = mat[0][1], n = mat[0][2];
    trans[0][0] = c;
    trans[0][1] = r;
    trans[0][2] = n;

    int k = 1;
    for (int col = 0; col < c; col++) {
        for (int i = 1; i <= n; i++) {
            if (mat[i][1] == col) {
                trans[k][0] = mat[i][1];
                trans[k][1] = mat[i][0];
                trans[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

void addSparse(int a[MAX][3], int b[MAX][3], int sum[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Matrices dimensions mismatch, cannot add!\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    int n1 = a[0][2], n2 = b[0][2];
    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];

    while (i <= n1 && j <= n2) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++; k++;
        } else if (b[j][0] < a[i][0] || (a[i][0] == b[j][0] && b[j][1] < a[i][1])) {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        } else {
            int temp = a[i][2] + b[j][2];
            if (temp != 0) {  
                sum[k][0] = a[i][0];
                sum[k][1] = a[i][1];
                sum[k][2] = temp;
                k++;
            }
            i++; 
            j++;
}
    }

    while (i <= n1) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= n2) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;
}

void multiplySparse(int a[MAX][3], int b[MAX][3], int result[MAX][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Matrices cannot be multiplied!\n";
        return;
    }

    int m = a[0][0], p = b[0][1];
    result[0][0] = m;
    result[0][1] = p;
    int k = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int x = 1; x <= a[0][2]; x++) {
                if (a[x][0] == i) {
                    for (int y = 1; y <= b[0][2]; y++) {
                        if (b[y][0] == a[x][1] && b[y][1] == j) {
                            sum += a[x][2] * b[y][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = sum;
                k++;
            }
        }
    }
    result[0][2] = k - 1;
}

int main() {
    int A[MAX][3], B[MAX][3], T[MAX][3], SUM[MAX][3], MUL[MAX][3];
    int choice;

    cout << "Enter first matrix (triplet form):\n";
    readSparse(A);
        do{
        cout << "\n===== MENU =====\n";
        cout << "1. Display Matrix A\n";
        cout << "2. Transpose of A\n";
        cout << "3. Add A + B\n";
        cout << "4. Multiply A * B\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Matrix A in triplet form:\n";
                printSparse(A);
                break;

            case 2:
                transpose(A, T);
                cout << "Transpose of A:\n";
                printSparse(T);
                break;

            case 3:
                cout << "Enter second matrix (triplet form) for addition:\n";
                readSparse(B);
                addSparse(A, B, SUM);
                cout << "Result of A + B:\n";
                printSparse(SUM);
                break;

            case 4:
                cout << "Enter second matrix (triplet form) for multiplication:\n";
                readSparse(B);
                multiplySparse(A, B, MUL);
                cout << "Result of A * B:\n";
                printSparse(MUL);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        } }
        while(choice!=0);
    return 0;
        
    }
