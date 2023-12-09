#include <iostream>
#include <string> 
using namespace std;

int menu() {
	string options[] = { "" };
	for (int i = 0; i < sizeof(options)/sizeof(options[0]); i++) {
		cout << i << ": " << options[i] << endl;
	};
	return 0;
};

int main() {
	cout << "Squiggle\n";
	menu();
	return 0; 
}