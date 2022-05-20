#include <list>
#include <fstream>
using namespace std;

int main() {
	constexpr int n = 300000000; //10e8
	list<int> a;
	for (int i = 0; i < n; i++)
		a.push_front(i);
	list<int>::const_iterator it;
	for(it = a.begin(); it != a.end(); ++it)
		;
	for (int i = 0; i < n; i++)
		a.insert(it, i);
	ofstream f("stllist.dat", ios::binary);
	for (auto x : a) {
		f.write((char*)&x, sizeof(int));
	}
}
