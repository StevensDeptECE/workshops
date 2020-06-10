#include <iostream>
using namespace std;

int main() {
  if (2 < 3) {
    cout << "yes\n";
  }

  if (4 > 5) {
    cout << "yes\n";    
  } else {
    cout << "no\n";
  }

  if (2 < 3)
    cout << "yes\n";
  cout << "I want to adda  second line...\n";

  if (4 > 5)
    cout << "yes\n";    
  else
    cout << "no\n";

  if (2 < 3) {
    cout << "yes\n";
    cout << "second statement";
  }

  for (int i = 0; i < 10; i++) {
     cout << i; // 0123456789
  }

#if 0
  while (true) {
     cout << "forever...";
  }
#endif

}