#include <bits/stdc++.h>
using namespace std;

int main() {
	set < int > s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	set < int > :: iterator it;
	for (it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
	s.erase(3);
	for (it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}