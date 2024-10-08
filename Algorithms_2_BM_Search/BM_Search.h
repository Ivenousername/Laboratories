#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cout;
using std::cin;

std::vector<int> shiftTable(const string& pattern);

std::vector<int> findInInterval(const string& text, const string& pattern, int from, int to, bool firstOccurrence);

int firstOccurrence(const string& searchQuery, const string& text);

std::vector<int> wholeText(const string& searchQuery, const string& text);

void findFirst(const string& text, const string& searchQuery);

void findAll(const string& text, const string& searchQuery);

void findInterval(const string& text, const string& searchQuery, int from, int to);
