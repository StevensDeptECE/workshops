#include <thread>
#include <iostream>
#include <unistd.h>

using namespace std;

void f() {
  for (;;) {
    cout << "hello" << endl;
    usleep(1000000);
  }
}

void g() {
  for (;;) {
    cout << "bye" << endl;
    usleep(1500000);
  }

}

int main() {
  thread t1(f); // hello bye hello bye
  thread t2(g);
  t1.join();
  t2.join();
}