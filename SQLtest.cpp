#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> v;
    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
		v.push_back(line);
	}

	cout << "#include <iostream>" << '\n';
	cout << "using namespace std;" << '\n';
	cout << "int main() {" << '\n';
	for(int i = 0; i<v.size(); i++){
		cout << "\tcout << \"" << v[i] << "\" << '\\n';" << '\n';
	}
	cout << "}";
	return 0;
}
