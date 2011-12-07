#include <fstream>
#include <iomanip>
#include <map>
#include <cmath>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main() {
	string a, b, c, junk, currentBlockName = "-";
	int currentBlockNo = 0;
	int counter = 0;
	int locctr[100]  = {0};
	map<string,int> m;
	map<string,int> symtab;
	map<int, string> reverseIndex;
	reverseIndex[0] = "-";
	m["-"] = counter++;
	ifstream in("inp");
	ofstream out("out");
	int i = 0;
	while (in >>  junk >> a >> b >> c && b != "END") {
		if (b == "USE") {
			if (!m.count(c)) {m[c] = counter++;reverseIndex[counter-1]=c;}
			currentBlockNo = m[c];
			currentBlockName = c;
		}
		i = currentBlockNo;
		ostringstream ss;
		ss << hex << setw(4) << setfill('0') <<locctr[i] << setfill(' ')<< " " << currentBlockNo << " " << a << " " << b << " " << c << endl;
		string line = ss.str();
		out << line;
		ofstream file;
		file.open(currentBlockName.c_str(),ios::app);
		file << line;
		file.close();

		if (a != "-") {
			if (symtab.count(a)) ;//cout << "Error" << a << endl;
			else symtab[a] = locctr[i];
		} 
		if (b == "START" || b == "END" || b == "USE" || b == "LTORG" || b == "EQU") continue;
		if (b[0] == '+') locctr[i] += 4;
		else if (b == "CLEAR" || b == "TIXR" || b== "COMPR") locctr[i] += 2;
		else if (b == "WORD") locctr[i] += 3;
		else if (b == "RESW") locctr[i] += 3 * atoi(c.c_str());
		else if (b == "RESB") locctr[i] += atoi(c.c_str());
		else if (b == "BYTE") {
			if (c[0] == 'C') locctr[i] += c.size() - 3;
			else locctr[i] += ceil((c.size()-3)/2.0);
		}
		else if (b[0] == '=' && b[1] == 'X') locctr[i] += ceil((b.size()-4)/2.0);
		else if (b[0] == '=' && b[1] == 'C') locctr[i] += b.size()-4;
		else locctr[i] += 3;
	}
	int address[100];
	address[0] = 0;
	for (int i=1;i < counter; i++) 
		address[i] = address[i-1] + locctr[i-1];
	for (int i=0;i<counter;i++) 
		printf("%-10s  %d  %4x  %4x\n", reverseIndex[i].c_str(), i, address[i],locctr[i]);
	return 0;
}


