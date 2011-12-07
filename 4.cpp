#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string junk, a;
	char str[100];
	ifstream in("inp");
	printf("R");
	while (in >> junk >> junk >> a >> str) 
		if (a == "EXTREF") 
			for (char *word=strtok(str,",");word;word=strtok(NULL,","))
				printf("%-6s", word);
	return 0;
}


