#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define TEST_LIM 10
#define N_LIM 100
#define VALUE_LIM 100

int main() {
	srand(time(NULL));
	for (int i = 0; i <= 4; i++) {
		string num(1, char(i + 48));
		string fileName = "/home/sauravchandra1/Documents/inp/inp0";
		fileName += num;
		const char * currentFileName = fileName.c_str();
		freopen(currentFileName, "w", stdout);
		int test;
		test = TEST_LIM;
		cout << test << endl;
		while (test--) {
			int n = rand() % N_LIM + 1;
			cout << n << endl;
			for (int i = 0; i < n; i++) {
				int val = rand() % VALUE_LIM + 1;
				cout << val << " ";
			}
			cout << endl;
		}
	}
	return 0;
}