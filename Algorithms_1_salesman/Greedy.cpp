#include "Greedy.h"
#include <iostream>

bool AvailableStep(int city, int* used_columns, int n_cities) {
    return used_columns[city] == 0; // Return true if the city has not been visited
}

void Greedy(int** matrix, int n_cities, int starting_city) {
    int* path = new int[n_cities + 1];
    int* used_columns = new int[n_cities]();
    int total_distance = 0; 

    // Initialize the path with the starting city
    path[0] = starting_city;
    used_columns[starting_city] = 1; // Mark starting city as visited

    // Iterate over the number of cities to build the path
    for (int i = 0; i < n_cities - 1; i++) {
        int min_in_row = INT_MAX;
        int current_step = -1;

        // Iterate over all cities to find the next step (unvisited city with the minimum distance)
        for (int j = 0; j < n_cities; j++) {
            if (matrix[path[i]][j] < min_in_row && AvailableStep(j, used_columns, n_cities)) {
                min_in_row = matrix[path[i]][j];
                current_step = j;
            }
        }
        path[i + 1] = current_step; // Update the path and mark the city as visited
        used_columns[current_step] = 1;

        total_distance += matrix[path[i]][current_step];
    }

    // Complete the path by returning to the starting city
    path[n_cities] = starting_city;
    total_distance += matrix[path[n_cities - 1]][starting_city];  // Add distance back to the starting city

    std::cout << "Path: ";
    for (int i = 0; i <= n_cities; i++) {
        std::cout << path[i] << " ";
    }
    std::cout << '\n';
    std::cout << "Total Distance: " << total_distance << '\n';

    delete[] used_columns;
    delete[] path;
}
