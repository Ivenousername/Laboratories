#include <iostream>
#include <cstdlib>
#include "Matrices.h"

int** CreateMatrix(int n) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	return matrix;
}
void FillMatrixRandom(int** matrix, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) matrix[i][j] = 0;
			else matrix[i][j] = rand() % 30 + 1;
		}
	}
}
void FillMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) { 
				matrix[i][j] = 0; 
			}
			else {
				std::cin >> matrix[i][j] ;
			}
		}
	}
}
void PrintMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}