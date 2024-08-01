#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int** matrix;
    

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void input() {
        cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    Matrix multiply(Matrix& other) {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied.\n";
            exit(1);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;
    cout << "Enter number of rows and columns for the first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter number of rows and columns for the second matrix: ";
    cin >> r2 >> c2;

    Matrix m1(r1, c1);
    Matrix m2(r2, c2);

    m1.input();
    m2.input();

    cout << "First matrix:\n";
    m1.print();
    cout << "Second matrix:\n";
    m2.print();

    Matrix m3 = m1.multiply(m2);
    cout << "Product matrix:\n";
    m3.print();

    return 0;
}
