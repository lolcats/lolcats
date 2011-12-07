#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;
#define REP(i, n) for(typeof(n) i=0;i<(n);++i)
#define foreach(it, c)for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
int main() {
	ifstream in("inp");
	string a, b, c;
	map<string, string> m;

	while (in >> a >> b >> c) {
		if (c[0] == '=') {
			string constant = c.substr(3,c.size()-4);
			if (m.count(a)) cout << "Duplicate literal found " << a << endl;
			if (c[1] == 'C') {
				ostringstream ss;
				REP(i,constant.size()) ss << hex << (int)constant[i];
				m[a] = ss.str();
			} else {
				m[a] = constant;
			}
		}
	}
	foreach(it, m) cout << it->first << " " << it->second << endl;
	return 0;
}


