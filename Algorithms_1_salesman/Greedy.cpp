#include "Greedy.h"
#include <iostream>

bool AvailableStep(int city, int* used_columns, int n_cities) {
    return used_columns[city] == 0;
}

int Greedy(int** matrix, int n_cities, int starting_city) {
    int* path = new int[n_cities + 1];
    int* used_columns = new int[n_cities]();
    int total_distance = 0; 
    path[0] = starting_city;
    used_columns[starting_city] = 1;
    for (int i = 0; i < n_cities - 1; i++) {
        int min_in_row = INT_MAX;
        int current_step = -1;

        for (int j = 0; j < n_cities; j++) {
            if (matrix[path[i]][j] < min_in_row && AvailableStep(j, used_columns, n_cities)) {
                min_in_row = matrix[path[i]][j];
                current_step = j;
            }
        }
        path[i + 1] = current_step;
        used_columns[current_step] = 1;

        total_distance += matrix[path[i]][current_step];
    }
    path[n_cities] = starting_city;
    total_distance += matrix[path[n_cities - 1]][starting_city]; 

    std::cout << "Path: ";
    for (int i = 0; i <= n_cities; i++) {
        std::cout << path[i] << " ";
    }
    std::cout << '\n';
    std::cout << "Total Distance: " << total_distance << '\n';

    delete[] used_columns;
    delete[] path;
	return total_distance;
}
