#include "BM_Search.h"

int* shiftTable(const string& pattern) {
	int m = pattern.length();
	int* table = new int[256];
	for (int i = 0; i < 256; i++) table[i] = m;
	for (int j = 0; j < m - 1; j++) table[pattern[j]] = m - 1 - j;
	return table;
}
vector<int> findInInterval(const string& text, const string& pattern, int from, int to, bool firstOccurrence) {
	int i, j, k = 0, p = 0;
	std::vector<int> array;
	if (to > text.size() - 1) {
		to = text.size() - 1;
	}

	int* table = shiftTable(pattern);
	i = from + pattern.size() - 1;

	while (i <= to) {
		j = pattern.size() - 1;
		k = i;

		while (j >= 0) {
			if (k < 0 || k >= text.size()) {
				break; 
			}

			if (text[k] == pattern[j]) {
				k = k - 1;
				j = j - 1;
			}
			else {
				int shift = table[static_cast<unsigned char>(text[k])];
				i = k + shift;
				break;
			}
		}

		if (j < 0) {
			array.push_back(k + 1);
			p = 1;
			if (firstOccurrence) {
				break;
			}
			i++;
		}
	}

	if (p == 0) {
		cout << "\nPattern not found\n";
	}

	return array;
}

int firstOccurrence(const string& text, const string& pattern) {
	std::vector<int> array = findInInterval(text, pattern, 0, text.size() - 1, true);
	if (!array.empty()) {
		return array.front();
	}
	return -1; 
}

vector<int> wholeText(const string& text, const string& pattern) {
	return findInInterval(text, pattern, 0, text.size() - 1, false);
}

void findFirst(const string& text, const string& pattern) {
	int index = firstOccurrence(pattern, text);
	cout << "\nPattern found at index  " << index << "\n";
	cout << "---------------\n";
}

void findAll(const string& text, const string& pattern) {
	std::vector<int> array = wholeText(text, pattern);
	cout << "\nAll pattern beginning indexes:  ";
	for (int n : array) {
		cout << n << " ";
	}
	cout << "\n---------------\n";
}

void findInterval(const string& text, const string& pattern, int from, int to) {
	std::vector<int> array = findInInterval(text, pattern, from, to, false);
	cout << "\nIn the text from " << from << " to " << to << "\nAnswer - ";
	for (int n : array) {
		cout << n << " ";
	}
	cout << "\n---------------\n";
}
