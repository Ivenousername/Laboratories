#include <iostream>
#include <chrono>
#include <iomanip>
#include "Matrices.h"
#include "BRUTEFORCE.h"
#include "Greedy.h"

int main() {
	srand(time(0));
	std::cout << "\nStarting city:  ";
	int starting_city = 0;
	for (int n = 4; n < 11;n+=3) {
		
		std::cout << "\n--------------------------------------------------------------------\n" << n << "x" << n << " matrix:\n";
		for (int j = 0; j < 3; j++) {

			int** matrix = CreateMatrix(n); 
			FillMatrixRandom(matrix, n);
			PrintMatrix(matrix, n);
			std::cout << '\n';
			auto start_greedy = std::chrono::high_resolution_clock::now();
			int g_distance = Greedy(matrix, n, starting_city);
			auto end_greedy = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time_greedy = end_greedy - start_greedy;
			std::cout << "Greedy execution time: " << time_greedy.count() << " seconds\n";

			auto start_bruteforce = std::chrono::high_resolution_clock::now();
			int bf_w_distance;
			int bf_distance = BruteForce(matrix, n, starting_city,bf_w_distance);
			auto end_bruteforce = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time_bruteforce = end_bruteforce - start_bruteforce;
			std::cout << "BruteForce execution time: " << time_bruteforce.count() << " seconds\n";

			std::cout << "The greedy algorithm is " << std::setprecision(2) <<
				(time_bruteforce > time_greedy ? time_bruteforce / time_greedy : time_greedy / time_bruteforce) <<
				(time_bruteforce < time_greedy ? " times slower\n" : " times quicker\n");
			std::cout << "The greedy algorithm is " << ((1 - (1.0f * (g_distance - bf_distance) / (bf_w_distance - bf_distance))) * 100)
			<< "% exact\n";
			DeleteMatrix(matrix, n);
		}
	}
}