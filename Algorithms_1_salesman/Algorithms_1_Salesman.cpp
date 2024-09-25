#include <iostream>
#include <chrono>
#include "Matrices.h"
#include "BRUTEFORCE.h"
#include "Greedy.h"

int main() {
	std::cout << "Matrix size:  ";
	int n;
	std::cin >> n;
	std::cout << "\nStarting city:  ";
	int starting_city;
	std::cin >> starting_city;

	int** matrix = CreateMatrix(n);
	FillMatrixRandom(matrix, n);
	PrintMatrix(matrix, n);
	std::cout << '\n';
	auto start_greedy = std::chrono::high_resolution_clock::now();
	Greedy(matrix, n, starting_city);
	auto end_greedy = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_greedy = end_greedy - start_greedy;
	std::cout << "Greedy execution time: " << elapsed_greedy.count() << " seconds\n";

	auto start_bruteforce = std::chrono::high_resolution_clock::now();
	BruteForce(matrix, n, starting_city);
	auto end_bruteforce = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_bruteforce = end_bruteforce - start_bruteforce;
	std::cout << "BruteForce execution time: " << elapsed_bruteforce.count() << " seconds\n";

	DeleteMatrix(matrix, n);
}
