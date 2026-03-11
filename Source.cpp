#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

const int MATRIX_SIZE = 4;
int Minor(int arr1[MATRIX_SIZE][MATRIX_SIZE], int i, int n);

// Function to find maximum and minimum element in the matrix
void findMaxMin(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int& maxVal, int& minVal, int& maxRow, int& maxCol, int& minRow, int& minCol) {
    maxVal = std::numeric_limits<int>::min(); // Set maxVal to smallest possible value
    minVal = std::numeric_limits<int>::max(); // Set minVal to largest possible value

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
}

// Function to transpose the matrix
void transpose(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = i + 1; j < MATRIX_SIZE; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// Function to rotate the matrix 90 degrees clockwise
void rot90(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {

    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE / 2; ++j) {
            std::swap(matrix[i][j], matrix[i][MATRIX_SIZE - 1 - j]);
        }
    }
}

// Function to rotate the matrix 90 degrees anticlockwise
void rot90anticlockwise(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    transpose(matrix);
    for (int j = 0; j < MATRIX_SIZE; ++j) {
        for (int i = 0; i < MATRIX_SIZE / 2; ++i) {
            std::swap(matrix[i][j], matrix[MATRIX_SIZE - 1 - i][j]);
        }
    }
}

// Function to get a row from the matrix
void GetRow(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int row) {
    std::cout << "Row " << row << ": ";
    for (int j = 0; j < MATRIX_SIZE; ++j) {
        std::cout << matrix[row][j] << " ";
    }
    std::cout << std::endl;
}

// Function to get a column from the matrix
void GetColumn(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int col) {
    std::cout << "Column " << col << ": ";
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        std::cout << matrix[i][col] << " ";
    }
    std::cout << std::endl;
}

// Function to get the diagonal vector of the matrix
std::vector<int> GetDiagonal(const int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    std::vector<int> diagonal;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        diagonal.push_back(matrix[i][i]);
    }
    return diagonal;
}

// Function to get the inverse diagonal vector of the matrix
std::vector<int> GetInverseDiagonal(const int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    std::vector<int> inverseDiagonal;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        inverseDiagonal.push_back(matrix[i][MATRIX_SIZE - 1 - i]);
    }
    return inverseDiagonal;
}

// Function to calculate the determinant of the matrix
int Determine(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int n)
{
    int i, M, sum = 0;

    int arr1[MATRIX_SIZE][MATRIX_SIZE]; // Declare arr1 matrix
    // Copy matrix elements to arr1
    for (int row = 0; row < MATRIX_SIZE; ++row) {
        for (int col = 0; col < MATRIX_SIZE; ++col) {
            arr1[row][col] = matrix[row][col];
        }
    }

    if (n == 1)//»¼°j²×¤î±ø¥ó
        return arr1[0][0];

    else if (n > 1)
    {
        for (i = 0; i < n; i++)
        {
            M = Minor(arr1, i, n);
            sum += pow(-1, i + 2) * arr1[0][i] * M;
        }
    }
    return sum;
}

int Minor(int arr1[MATRIX_SIZE][MATRIX_SIZE], int i, int n)
{
    int j, k, result;
    int arr2[MATRIX_SIZE][MATRIX_SIZE];
    for (j = 0; j < n - 1; j++)
    {
        for (k = 0; k < n - 1; k++)
        {
            if (k < i)
                arr2[j][k] = arr1[j + 1][k];
            else if (k >= i)
                arr2[j][k] = arr1[j + 1][k + 1];
        }
    }
    return Determine(arr2, n - 1);
}

// Function to invert the matrix
void InvertMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int det) {
    std::cout << "InvertMatrix " << ": " << std::endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            std::cout << matrix[i][j] / det;
        }
        std::cout << std::endl;
    }
}




int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int maxVal, minVal, maxRow, maxCol, minRow, minCol;

    // Find max and min values and their positions
    findMaxMin(matrix, maxVal, minVal, maxRow, maxCol, minRow, minCol);
    std::cout << "Maximum value: " << maxVal << " at row " << maxRow << " and column " << maxCol << std::endl;
    std::cout << "Minimum value: " << minVal << " at row " << minRow << " and column " << minCol << std::endl;

    // Transpose the matrix
    transpose(matrix);
    std::cout << "Transposed matrix:" << std::endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Rotate the matrix 90 degrees clockwise
    rot90(matrix);
    std::cout << "Rotated matrix 90 degrees clockwise:" << std::endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Rotate the matrix 90 degrees anticlockwise
    rot90anticlockwise(matrix);


    // Get row index from user
    int rowIndex;
    std::cout << "Enter row index (0-" << MATRIX_SIZE - 1 << "): ";
    std::cin >> rowIndex;
    while (rowIndex < 0 || rowIndex >= MATRIX_SIZE) {
        std::cout << "Invalid row index. Please enter a valid row index (0-" << MATRIX_SIZE - 1 << "): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> rowIndex;
    }
    GetRow(matrix, rowIndex);

    // Get column index from user
    int colIndex;
    std::cout << "Enter column index (0-" << MATRIX_SIZE - 1 << "): ";
    std::cin >> colIndex;
    while (colIndex < 0 || colIndex >= MATRIX_SIZE) {
        std::cout << "Invalid column index. Please enter a valid column index (0-" << MATRIX_SIZE - 1 << "): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> colIndex;
    }
    GetColumn(matrix, colIndex);

    // Get diagonal vector
    std::vector<int> diagonal = GetDiagonal(matrix);
    std::cout << "Diagonal vector:" << std::endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        std::cout << diagonal[i] << " ";
    }
    std::cout << std::endl;

    // Get inverse diagonal vector
    std::vector<int> inverseDiagonal = GetInverseDiagonal(matrix);
    std::cout << "Inverse diagonal vector:" << std::endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        std::cout << inverseDiagonal[i] << " ";
    }
    std::cout << std::endl;

    // Get Determinant
    int det = Determine(matrix, MATRIX_SIZE);
    std::cout << "Determinant: " << det << std::endl;

    // Check if invertible and find inverse if possible
    if (det == 0) {
        std::cout << "Because Determinant = 0, so there isn't InvertMatrix " << std::endl;
    }
    else if (det != 0) {
        InvertMatrix(matrix, det);
    }

    return 0;
}
