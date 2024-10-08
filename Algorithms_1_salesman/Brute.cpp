﻿#include "BRUTEFORCE.H"
void Swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

bool NextPerm(int* current_perm, int n) {
	int i = n - 2;
	while (i >= 0 && current_perm[i] >= current_perm[i + 1]) {
		i--;
	}
	if (i < 0) {
		return false;
	}
	int j = n - 1;
	while (current_perm[j] <= current_perm[i]) {
		j--;
	}
	Swap(current_perm[i], current_perm[j]);
	int left = i + 1, right = n - 1;
	while (right > left) {
		Swap(current_perm[right], current_perm[left]);
		left++;
		right--;
	}

	return true;
} 

int Distance(int** matrix, int* current_perm, int n) {
	int total = 0;
	for (int i = 0; i < n - 1; i++) {
		total += matrix[current_perm[i]][current_perm[i + 1]];
	}
	total += matrix[current_perm[n - 1]][current_perm[0]];
	return total;
}
void Rotate(int* permutation, int n, int starting_city) {
	while (permutation[0] != starting_city) {
		int temp = permutation[0];
		for (int i = 0; i < n; i++) {
			permutation[i] = permutation[i + 1];
		}
		permutation[n - 1] = temp;
	}
}
int BruteForce(int** matrix, int n_cities, int starting_city, int& bruteforceworst) {
	int min_distance = INT_MAX;
	int max_distance = INT_MIN;
	int* current_perm = new int[n_cities];
	for (int i = 0; i < n_cities; i++) {
		current_perm[i] = i;
	}
	int* best_perm = new int[n_cities];
	int current_distance = 0;

	do {
		current_distance = Distance(matrix, current_perm, n_cities);
		if (current_distance < min_distance) {
			min_distance = current_distance;
			for (int i = 0; i < n_cities; i++) {
				best_perm[i] = current_perm[i];
			}
		}
		else if (current_distance > min_distance) {
			max_distance = current_distance;
		}
	} while (NextPerm(current_perm, n_cities));

	Rotate(best_perm, n_cities, starting_city); 
	std::cout << "\nThe best permutation: ";
	for (int i = 0; i < n_cities; i++) {
		std::cout << best_perm[i] << ' ';
	}
	std::cout << best_perm[0];
	std::cout << "\nMinimum distance: " << min_distance << std::endl;
	std::cout << "\Maximum distance: " << max_distance << std::endl;
	bruteforceworst = max_distance;
	delete[] current_perm;
	delete[] best_perm;
	return min_distance;
}