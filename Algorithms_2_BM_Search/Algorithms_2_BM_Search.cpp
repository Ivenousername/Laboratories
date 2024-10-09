#include "BM_Search.h"
int main() { //findInterval, findAll, findFirst
	string text = "r is an iterator adaptor which behaves exactly like the underlying iterator";
	string pattern = "tor";
	findAll(text, pattern);
	findFirst(text, pattern);

	return 0;
}
