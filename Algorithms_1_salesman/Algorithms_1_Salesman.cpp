#include <iostream>
#include <chrono>
#include <iomanip>
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

	int** matrix = CreateMatrix(n); //Creating the matrix and printing it out
	FillMatrixRandom(matrix, n);
	PrintMatrix(matrix, n);
	std::cout << '\n';

	auto start_greedy = std::chrono::high_resolution_clock::now(); 
	Greedy(matrix, n, starting_city);
	auto end_greedy = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_greedy = end_greedy - start_greedy;
	std::cout << "Greedy execution time: " << time_greedy.count() << " seconds\n";

	auto start_bruteforce = std::chrono::high_resolution_clock::now();
	BruteForce(matrix, n, starting_city);
	auto end_bruteforce = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_bruteforce= end_bruteforce - start_bruteforce;
	std::cout << "BruteForce execution time: " << time_bruteforce.count() << " seconds\n";

	std::cout << "The greedy algorithm is " << std::setprecision(2) <<
		(time_bruteforce>time_greedy? time_bruteforce/time_greedy : time_greedy/time_bruteforce) << 
		(time_bruteforce < time_greedy ? " times slower" : " times quicker");
	DeleteMatrix(matrix, n);
}
