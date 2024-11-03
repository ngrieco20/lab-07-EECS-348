#include <iostream>
#include <fstream>  
using namespace std;

const int SIZE = 4; // assigns the size of matrix 

class Matrix {
private:
    int data[SIZE][SIZE];

public:
    // function that reads the matrices from the file matrix.txt 
    void readFromFile(const string& filename, Matrix& mat2) {
        //error handling
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        // iterates thru the rows/ columns of first matrix 
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                inputFile >> data[i][j];
            }
        }

        // iterates thru the rows/ columns of ssecond matrix 
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                inputFile >> mat2.data[i][j];
            }
        }

        inputFile.close();  // closes the file after reading inputfile
    }

    // displays the matrix 
    void display() const {
        //iterates through the rows and columns of matrix print for output 
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl; // prints the output 
        }
    }

    // overload + operator function 
    Matrix operator+(const Matrix& other) const {
        Matrix result; // stores result for addition 
        
        // iterates through each row and column and adds values from matrix 1 and matrix 2 
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result; // returns the sum 
    }

    // overload * operator function 
    Matrix operator*(const Matrix& other) const {
        Matrix result; // stores result for multiplication
        // iterates through each row adn column and multiplies values from matrix 1 and matrix 2 
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = 0; // sets elemnet = 0 
                
                // calculautes each elemnt in matrix  as the sum of 2 matrices multiplied together (product)
                for (int k = 0; k < SIZE; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result; // returs product 
    }

// sum of diagonals function 
int sumOfDiagonals() const {
    int mainDiagonalSum = 0;      // sum of main diagonal elements

    for (int i = 0; i < SIZE; ++i) {
        mainDiagonalSum += data[i][i];  // main element 
    }
    // returns the sum 
    return mainDiagonalSum; 
}


    // Function to swap two rows
    void swapRows(int row1, int row2) {
        // checks for valid row indices 
        if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
            // swaps element in specified row called in main function 
            for (int j = 0; j < SIZE; ++j) {
                swap(data[row1][j], data[row2][j]);
            }
        } else {  
            cout << "Invalid row indices!" << endl; // error handling 
        }
    }
};

int main() {
    Matrix mat1, mat2;
    string filename;

    // ask user for filename to read 
    cout << "Enter the filename to read matrices: ";
    cin >> filename;

    // reads matrix 1 and matrix 2 from file 
    mat1.readFromFile(filename, mat2);
    
    cout << "\n Matrix 1:" << endl << endl; 
    mat1.display();

    cout << "\nMatrix 2:" << endl << endl;
    mat2.display();

    // performs matrix addition 
    Matrix sum = mat1 + mat2;
    cout << "\nSum of matrices:" << endl << endl;
    sum.display();  // displays the sum 

    // performs matrix multiplicaiton 
    Matrix product = mat1 * mat2;
    cout << "\nProduct of matrices:" << endl << endl; 
    product.display(); // displays the product 

    // display the sum diagonal of matrix 1 
    int mat1DiagonalSum = mat1.sumOfDiagonals();
    cout << "\nSum of diagonals of Matrix 1: " << mat1DiagonalSum << endl;

    // display the sum diagonal of matrix 2 
    int mat2DiagonalSum = mat2.sumOfDiagonals();
    cout << "\nSum of diagonals of Matrix 2: " << mat2DiagonalSum << endl;

    // swaps rows and shows result 
    mat1.swapRows(0, 2);
    cout << "\nMatrix 1 after swapping rows:" << endl << endl; 
    mat1.display();

    mat2.swapRows(0, 2);
    cout << "\nMatrix 2 after swapping rows:" << endl << endl; 
    mat2.display();

    return 0;
}
