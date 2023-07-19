#include <thread>
#include <iostream>
#include <unistd.h>
#include <cmath>

using namespace std;
/*
  n=1000000

this is too coarse grained, the right side is much more work
because the numbers are bigger
  1.. 500,000   500,001.. 1,000,000

this is better, you can load balance (except at the end)
    1.. 100k, 100,001..200k, 200,001..300k ...

this is too fine grained:
  1..10  11..20  21..30, ...
*/
static inline bool isPrime(uint64_t a) {
    for (uint64_t i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}
uint64_t countPrimes(uint64_t a, uint64_t b) {
  uint64_t count = 0;
  for (uint64_t i = a; i <= b; i++) {
    if (isPrime(i)) {
      count++;
    }
  }
  return count;
}

// multithreaded version
void countPrimes(uint64_t a, uint64_t b, uint64_t* primeCount) {
 uint64_t count = 0;
  for (uint64_t i = a; i <= b; i++) {
    if (isPrime(i)) {
      count++;
    }
  }
  *primeCount = count;
}



int main(int argc, char* argv[]) {
  const uint64_t n = argc > 1 ? atoi(argv[1]) : 1000000;
  cout << countPrimes(2, n) << endl;
  uint64_t prime1, prime2;
  thread t1(&countPrimes, (2, n/2, &prime1));
  thread t2(&countPrimes, (n/2+1, n, &prime2));
  t1.join();
  t2.join();
  cout << (prime1 + prime2) << endl;
}