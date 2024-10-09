#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::cin;

int* shiftTable(const string& pattern);

vector<int> BM_Search(const string& text, const string& pattern, int from, int to, bool firstOccurrence);

int firstOccurrence(const string& searchQuery, const string& text);

vector<int> wholeText(const string& searchQuery, const string& text);

void findFirst(const string& text, const string& searchQuery);

void findAll(const string& text, const string& searchQuery);

void findInterval(const string& text, const string& searchQuery, int from, int to);
