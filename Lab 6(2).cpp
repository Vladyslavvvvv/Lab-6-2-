#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <class T>
class MatrixCopy {
private:
    T** matrix;
    int rows;
    int columns;

public:
    MatrixCopy(int rows, int columns);
    ~MatrixCopy();
    void copyByRows(int row);
    void copyByColumns(int column);
    void copySelectedRow(int sourceRow, int destRow);
    void copySelectedColumn(int sourceColumn, int destColumn);
    void copyMainDiagonal();
    void printMatrix() const;
    void printMainDiagonal() const;
    void fillRandomValues(T minValue, T maxValue);
};

template <class T>
MatrixCopy<T>::MatrixCopy(int rows, int columns) : rows(rows), columns(columns) {
    matrix = new T * [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new T[columns];
    }
}

template <class T>
MatrixCopy<T>::~MatrixCopy() {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <class T>
void MatrixCopy<T>::copyByRows(int row) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = matrix[row][j];
        }
    }
}

template <class T>
void MatrixCopy<T>::copyByColumns(int column) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = matrix[i][column];
        }
    }
}

template <class T>
void MatrixCopy<T>::copySelectedRow(int sourceRow, int destRow) {
    for (int j = 0; j < columns; ++j) {
        matrix[destRow][j] = matrix[sourceRow][j];
    }
}

template <class T>
void MatrixCopy<T>::copySelectedColumn(int sourceColumn, int destColumn) {
    for (int i = 0; i < rows; ++i) {
        matrix[i][destColumn] = matrix[i][sourceColumn];
    }
}

template <class T>
void MatrixCopy<T>::copyMainDiagonal() {
    int minDim = min(rows, columns);
    for (int i = 0; i < minDim; ++i) {
        matrix[i][i] = matrix[i][i];
    }
}

template <class T>
void MatrixCopy<T>::printMatrix() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

template <class T>
void MatrixCopy<T>::printMainDiagonal() const {
    int minDim = min(rows, columns);
    for (int i = 0; i < minDim; ++i) {
        cout << matrix[i][i] << ' ';
    }
    cout << '\n';
}

template <class T>
void MatrixCopy<T>::fillRandomValues(T minValue, T maxValue) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = rand() % (maxValue - minValue + 1) + minValue;
        }
    }
}

int main() {
    int rows, columns;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> columns;

    MatrixCopy<int> intMatrix(rows, columns);
    int minValue, maxValue;
    cout << "Enter the minimum and maximum values for random filling (int): ";
    cin >> minValue >> maxValue;
    intMatrix.fillRandomValues(minValue, maxValue);

    cout << "Generated Integer Matrix:\n";
    intMatrix.printMatrix();
    cout << "-----------------\n";

    MatrixCopy<double> doubleMatrix(rows, columns);
    double doubleMinValue, doubleMaxValue;
    cout << "Enter the minimum and maximum values for random filling (double): ";
    cin >> doubleMinValue >> doubleMaxValue;
    doubleMatrix.fillRandomValues(doubleMinValue, doubleMaxValue);

    cout << "Generated Double Matrix:\n";
    doubleMatrix.printMatrix();
    cout << "-----------------\n";

    MatrixCopy<char> charMatrix(rows, columns);
    char charMinValue, charMaxValue;
    cout << "Enter the minimum and maximum values for random filling (char): ";
    cin >> charMinValue >> charMaxValue;
    charMatrix.fillRandomValues(charMinValue, charMaxValue);

    cout << "Generated Char Matrix:\n";
    charMatrix.printMatrix();
    cout << "-----------------\n";

    return 0;
}