#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
int main() {
	string a, b, c;
	int currentBlockNo = 0;
	int counter = 0;
	map<string,int> m;
	m["-"] = counter++;
	ifstream in("inp");
	ofstream out("out");
	while (in >> a >> b >> c) {
		if (b == "USE") {
			if (!m.count(c)) m[c] = counter++;
			currentBlockNo = m[c];
		}
		out << currentBlockNo <<" " << a << " " << b << " " <<  c << endl;
	}
	for (map<string,int>::iterator it = m.begin(); it != m.end(); ++it)
		cout << it->first << " " << it->second << endl;
	return 0;
}


