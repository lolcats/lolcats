#include <string>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
	ifstream in("inp");
	map<string, string> m;
	int no  = 0;
	string a, b, c;
	while (in >> a >> b >> c) if (b == "EQU") m[a] = c;
	cin >> a;
	for (;m.count(a) && m[a]!="1"; a=m[a], no++);
	cout << no << endl;
	return 0;
}


