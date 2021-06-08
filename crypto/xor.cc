#include <iostream>

using namespace std;

int main() {
	char buffer[1024];
	cin.getline(buffer, sizeof(buffer));

	const char key = 'a';
	for (int i = 0; buffer[i] != '\0'; i++)
		cout << (int)(buffer[i] ^ key) << ' ';
	cout << '\n';
}
