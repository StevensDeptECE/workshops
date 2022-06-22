#include <iostream>
#include <iomanip>
#include <numbers>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
using namespace std::numbers;
using namespace std;
using namespace glm;

void print(const mat4& m) {
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      cout << setw(14) << m[r][c];
    }
    cout << '\n';
  }
  cout << "\n\n";
}

ostream& operator <<(ostream& s, const mat4& m) {
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      s << setw(14) << m[r][c];
    }
    s << '\n';
  }
  s << "\n\n";
  return s;
}

int main() {
  
  mat4 m1(1); // identity;
  print(m1);

  mat4 m2(3);
//  print(m2);
  cout << m2;

  mat4 m3(1);
  m3 = scale(m3, vec3(1,2,3));
  print(m3);

  m3 = translate(m3, vec3(4,-1,2));
  print(m3);

  mat4 m4(1);
  m4 = rotate(m4, glm::radians(45.0f), vec3(1,0,0));
  print(m4);

  mat4 m5(1);
  m5 = rotate(m5, glm::radians(45.0f), vec3(0.5,0.7,1.9));
  m5 = rotate(m5, glm::radians(45.0f), vec3(0.5,0.7,1.9));
  m5 = rotate(m5, glm::radians(45.0f), vec3(0.5,0.7,1.9));
  m5 = rotate(m5, glm::radians(45.0f), vec3(0.5,0.7,1.9));
  print(m5);

  constexpr float INV_SQRT3 = 1.0/sqrt(3);
  mat4 m6(1);
  m6 = rotate(m6, glm::radians(45.0f), vec3(INV_SQRT3,INV_SQRT3,INV_SQRT3));
  m6 = rotate(m6, glm::radians(45.0f), vec3(INV_SQRT3,INV_SQRT3,INV_SQRT3));
  m6 = rotate(m6, glm::radians(45.0f), vec3(INV_SQRT3,INV_SQRT3,INV_SQRT3));
  m6 = rotate(m6, glm::radians(45.0f), vec3(INV_SQRT3,INV_SQRT3,INV_SQRT3));
  print(m6);

}