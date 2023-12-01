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
    void fillRandomValues(int minValue, int maxValue);
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
    int minDim = std::min(rows, columns);
    for (int i = 0; i < minDim; ++i) {
        cout << matrix[i][i] << ' ';
    }
    cout << '\n';
}

template <class T>
void MatrixCopy<T>::fillRandomValues(int minValue, int maxValue) {
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

    MatrixCopy<int> matrixCopy(rows, columns);

    int minValue, maxValue;
    cout << "Enter the minimum and maximum values for random filling: ";
    cin >> minValue >> maxValue;

    matrixCopy.fillRandomValues(minValue, maxValue);

    cout << "Generated Matrix:\n";
    matrixCopy.printMatrix();
    cout << "-----------------\n";

    int choice;
    cout << "Choose operation:\n";
    cout << "1. Copy by rows\n";
    cout << "2. Copy by columns\n";
    cout << "3. Copy selected row\n";
    cout << "4. Copy selected column\n";
    cout << "5. Copy main diagonal\n";
    cin >> choice;

    switch (choice) {
    case 1:
        int rowToCopy;
        cout << "Enter the row to copy: ";
        cin >> rowToCopy;
        matrixCopy.copyByRows(rowToCopy);
        break;
    case 2:
        int colToCopy;
        cout << "Enter the column to copy: ";
        cin >> colToCopy;
        matrixCopy.copyByColumns(colToCopy);
        break;
    case 3:
        int sourceRow, destRow;
        cout << "Enter the source and destination rows: ";
        cin >> sourceRow >> destRow;
        matrixCopy.copySelectedRow(sourceRow, destRow);
        break;
    case 4:
        int sourceCol, destCol;
        cout << "Enter the source and destination columns: ";
        cin >> sourceCol >> destCol;
        matrixCopy.copySelectedColumn(sourceCol, destCol);
        break;
    case 5:
        matrixCopy.copyMainDiagonal();
        cout << "Main Diagonal:\n";
        matrixCopy.printMainDiagonal();
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    if (choice != 5) {
        cout << "Result Matrix:\n";
        matrixCopy.printMatrix();
    }

    return 0;
}