#pragma once
#include <iostream>

bool AvailableStep(int city, int* used_columns, int n_cities);

int Greedy(int** matrix, int n_cities, int starting_city);
