#include <iostream> 
#include <string> 
#include <vector> 
using namespace std;
class MatrixCipher {
private:
	int rows;
	int columns;
	vector<vector<char>> matrix;

public:
	MatrixCipher(int rowSize, int colSize) : rows(rowSize), columns(colSize), matrix(rowSize, vector<char>(colSize, ' ')) {}

	string encrypt(const string& text) {
		matrix.resize(rows, vector<char>(columns, ' '));

		for (int i = 0; i < text.length(); ++i) {
			matrix[i / columns][i % columns] = text[i];
		}

		string encrypted;
		for (int j = 0; j < columns; j++) {
			for (int i = 0; i < rows; i++) {
				if (matrix[i][j] != ' ') encrypted += matrix[i][j];
			}
		}
		return encrypted;
	}

	string decrypt(const string& text) {

		string decrypted;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				decrypted += matrix[i][j];
			}
		}
		return decrypted;
	}

	void printMatrix() const {
		for (const auto& row : matrix) {
			for (char c : row) {
				cout << (c == ' ' ? '.' : c) << ' ';
			}
			cout << endl;
		}
	}

};
