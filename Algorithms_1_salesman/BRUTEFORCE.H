#pragma once
#include <iostream>
void Swap(int& a, int& b);

bool NextPerm(int* current_perm, int n);

int Distance(int** matrix, int* current_perm, int n);

void Rotate(int* permutation, int n, int starting_city);

void BruteForce(int** matrix, int n_cities, int starting_city);
