#include "BRUTEFORCE.H"
void Swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

bool NextPerm(int* current_perm, int n) {
	/* Находим максимальное значение i такое, что
	0 < i < n и P[i] < P[i + 1].*/
	int i = n - 2;
	while (i >= 0 && current_perm[i] >= current_perm[i + 1]) {
		i--;
	}
	// Если такого i не существует, то процесс завершен – следующей перестановки нет, иначе п.2.
	if (i < 0) return false;

	// Находим максимальное значение j такое, что P[i] < P[j].
	int j = n - 1;
	while (current_perm[j] <= current_perm[i]) {
		j--;
	}
	// Меняем P[i] и P[j] местами. 
	Swap(current_perm[i], current_perm[j]);

	// Упорядывачиваем хвост (инвертирум порядок)
	int left = i + 1, right = n - 1;
	while (right > left) {
		Swap(current_perm[right], current_perm[left]);
		left++;
		right--;
	}

	return true;
} //Dijkstra's algorithm

int Distance(int** matrix, int* current_perm, int n) { //Takes a permutation and returns the distance
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
int BruteForce(int** matrix, int n_cities, int starting_city) {
	int min_distance = INT_MAX;
	int* current_perm = new int[n_cities];
	for (int i = 0; i < n_cities; i++) { //setting the first permutation to be [0,1,2,3...]
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
	} while (NextPerm(current_perm, n_cities));

	Rotate(best_perm, n_cities, starting_city); 
	std::cout << "\nThe best permutation: ";
	for (int i = 0; i < n_cities; i++) {
		std::cout << best_perm[i] << ' ';
	}
	std::cout << best_perm[0];
	std::cout << "\nMinimum distance: " << min_distance << std::endl;

	delete[] current_perm;
	delete[] best_perm;
	return min_distance;
}
int BruteForceWorst(int** matrix, int n_cities, int starting_city) {
	int max_distance = INT_MIN;
	int* current_perm = new int[n_cities];
	for (int i = 0; i < n_cities; i++) {
		current_perm[i] = i;
	}
	int* best_perm = new int[n_cities];
	int current_distance = 0;

	do {
		current_distance = Distance(matrix, current_perm, n_cities);
		if (current_distance > max_distance) {
			max_distance = current_distance;
			for (int i = 0; i < n_cities; i++) {
				best_perm[i] = current_perm[i];
			}
		}
	} while (NextPerm(current_perm, n_cities));

	Rotate(best_perm, n_cities, starting_city); 
	std::cout << "\nThe worst permutation: ";
	for (int i = 0; i < n_cities; i++) {
		std::cout << best_perm[i] << ' ';
	}
	std::cout << best_perm[0];
	std::cout << "\nMinimum distance: " << max_distance << std::endl;

	delete[] current_perm;
	delete[] best_perm;
	return max_distance;
}