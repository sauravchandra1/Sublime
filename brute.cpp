#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip> 
#include <cmath>
#include <climits>
#include <stack>
// #include <unistd.h>
using namespace std;

// string getcwd_string(void) {
//    char buff[PATH_MAX];
//    getcwd(buff, PATH_MAX );
//    string cwd(buff);
//    return cwd;
// }

int main() {
	for (int i = 0; i <= 4; i++) {
		string num(1, char(i + 48));
		string inputFileName = "/home/sauravchandra1/Documents/inp/inp0";
		string outputFileName = "/home/sauravchandra1/Documents/out/out0";
		inputFileName += num;
		outputFileName += num;
		const char * currentInputFileName = inputFileName.c_str();
		const char * currentOutputFileName = outputFileName.c_str();
		freopen(currentInputFileName, "r", stdin);
		freopen(currentOutputFileName, "w", stdout);
		//Code starts from here

		int T, N, A[5000];
		scanf("%d", & T);
		for (; T--;) {
			scanf("%d", & N);
			for (int i = 0; i < N; i++) {
				scanf("%d", & A[i]);
			}
			bool flag = false;
			for (int i = 0; i < N; i++) {
				for (int j = i + 2; j < N; j++) {
					if (A[i] == A[j]) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			puts(flag ? "YES" : "NO");
		}



	}
	return 0;
}