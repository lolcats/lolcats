#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ifstream in("inp");
	string addr, a, junk;
	char str[100];
	map<string, string> m;
	while (in >> addr >> a >> junk >> junk) if (a != "-") m[a] = addr;
	in.clear(); in.seekg(0,ios::beg);
	cout << "D";
	while (in >> junk >> junk >> a >> str) 
		if (a == "EXTDEF") 
			for (char *word=strtok(str,",");word;word=strtok(NULL,","))
				cout<<setw(6)<<setfill(' ')<<left<<word<<setw(6)<<setfill('0')<<m[word];
	return 0;
}


