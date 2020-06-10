#include <iostream>

using namespace std;

//   < <= > >= ==  !=        ! =  NOT THE SAME as !=
int main() {
 
  for (int i = 1; i <= 10; i++)
    cout << i;
  cout << '\n';

  for (int i = 1; i <= 1024; i *= 2)
    cout << i << ' ';
  cout << '\n';

//debugging: see this loop has sum uninitialized!
  int sum;
  for (int i = 1; i <= 100; i++) {
    sum += i;
  //  cout << sum << '\n'; // you can insert a print into the loop but this is not the best way. Too slow. USE THE DEBUGGER!
  }
  cout << sum << '\n';
}