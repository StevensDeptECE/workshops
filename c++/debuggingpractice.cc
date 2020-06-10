/*
  Fix my code and make it work!
  Compute n!
*/
int main() {
  const int n = 15; // your job: compute 15!
  int prod;
  for (int i = 0; i < n; i++)
    prod *= i;
  cout << prod;
}