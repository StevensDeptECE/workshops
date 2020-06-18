#include <iostream>
using namespace std;
#define CSI "\033["

class Screen {
public:
  Screen()  {}
  void text(int r, int c, const char s[]) {
    cout << CSI << r << ';' << c << 'H' << s;
  }
  void fg(int r, int g, int b) {
    cout << CSI << "38;2;" << r << ';' << g << ';' << b << 'm';
  }
  void bg(int r, int g, int b) {
    cout << CSI << "48;2;" << r << ';' << g << ';' << b << 'm';
  }

};


int main() {

  Screen s;
  s.text(1,1, "hello");
  s.fg(255, 0, 0);
  s.bg(0, 0, 255);
  s.text(1, 50, "bye");
  for (int i = 2; i < 16; i++) {
    s.fg(i*16, 0, 0);
    s.text(i, 1, "testing");
  }
#if 0
  cout << CSI  "38;2;255;0;0m";
  cout << CSI "H testing";
  cout << CSI "1;30Hyoho";
#endif

}