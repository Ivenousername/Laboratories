#include <iostream>
#include "Matrices.h"
int* NextPerm(int* current_perm) {
	return current_perm;
}
int BruteForce(int** matrix, int n_cities, int starting_city) {
	int min_value = INT_MAX;
	int* current_perm = new int[n_cities];
	current_perm[0] = 0;
	int n_perm = 1;
	for (int i = 1; i < n_cities; i++) {
		current_perm[i] = i;
		n_perm *= i;

	} //current perm is like [0 1 2 3 4] 
	int current_weight = 0;
	for (int i = 0; i < n_perm-1; i++) { //Counting the weight of the current permutation
		for(int j=0;j<n_cities)
		current_weight += matrix[current_perm[i]][current_perm[i + 1]];
	}
}
int main()
{
	std::cout << "Matrix size:  ";
	int n;
	std::cin >> n;
	std::cout << "\nStarting city:  ";
	int starting_city;
	std::cin >> starting_city;
	
	int** matrix = CreateMatrix(4);
	FillMatrixRandom(matrix, 4);
	PrintMatrix(matrix, 4);

	std::cout << '\n' << BruteForce(matrix,n,starting_city);

}
