#include <immintrin.h>
#include <iostream>
#include <cstdint>
#include <openssl/rand.h>
#include <cmath>

using namespace std;

class Stats {
private:
  double sumX, sumY, sumXY, sumXX, sumYY;
  uint32_t n;
public:
  Stats() : sumX(0), sumY(0), sumXY(0), sumXX(0), sumYY(0), n(0) {}
  void add(double x, double y) {
    sumX += x;
    sumY += y;
    sumXY += x * y;
    sumXX += x * x;
    sumYY += y * y;
    n++;
  }
  double corr() const {
    return (n * sumXY - sumX * sumY) /
      sqrt((n * sumXX - sumX * sumX) * (n * sumYY - sumY * sumY));
  }
};

void genRand1(uint64_t* ptr, uint32_t n) {
  unsigned long long* p = (unsigned long long*)ptr;
  uint32_t countGood = 0;
  for (uint32_t i = 0; i < n; i++)
    if (__builtin_ia32_rdrand64_step (p+i))
      countGood++;
  if (countGood != n)
    cerr << "random number generator fail " << countGood << "\n";
}

void genRand2(uint64_t* ptr, uint32_t n) {
  unsigned long long* p = (unsigned long long*)ptr;
  uint32_t countGood = 0;
  for (uint32_t i = 0; i < n; i++)
    countGood += __builtin_ia32_rdrand64_step (p+i);
  if (countGood != n)
    cerr << "random number generator fail " << countGood << "\n";
}

void genRand3(uint64_t* p, uint32_t n) {
  int rc = RAND_set_rand_method(RAND_get_rand_method());
  if (!rc)
    throw "failure to set random method";
  rc = RAND_bytes((uint8_t*)p, n*sizeof(uint64_t)); // fill block with random numbers
  if (!rc)
    throw "failure to randomize block";
}

void genRand4(uint64_t* ptr, uint32_t n) {
  unsigned long long* p = (unsigned long long*)ptr;
  uint32_t countGood = 0;
  for (uint32_t i = 0; i < n; i++)
    countGood += __builtin_ia32_rdseed_di_step(p+i);
  if (countGood != n)
    cerr << "random number generator fail " << countGood << "\n";
}


const int hist_bins = 128;

void displayHist(const uint32_t hist[], double expected, int n)  {
  double var = 0;
  for (int i = 0; i < hist_bins; i++)
    var += (hist[i]-expected)*(hist[i]-expected);
  var /= n;
  cout << var << '\n';
}

void varHistBits(uint32_t hist[64], uint32_t n) {
  uint64_t sum = 0;
  for (int i = 0; i < 64; i++)
    sum += (hist[i] - n/2) * (hist[i] - n/2);
  cout << "variance of bit values: " << sum << '\n';
}

void countHistBits1(const uint64_t p[], uint32_t n, uint32_t hist[64]) {
  for (uint32_t i = 0; i < 64; i++)
    hist[i] = 0;
  for (uint32_t i = 0; i < n; i++) {
    for (uint64_t j = 64, mask = 1; j > 0; j--, mask <<= 1)
      if (p[i] & j)
	hist[j]++;
  }
}

void countHistBits2(const uint64_t p[], uint32_t n, uint32_t hist[64]) {
  for (uint64_t i = 0, mask = 1; i < 64; i++, mask <<= 1) {
    uint64_t countOnes = 0;
    for (uint32_t i = 0; i < n; i++) {
      if (p[i] & mask)
	countOnes++;
    }
    hist[i] = countOnes;
  }
}

void countHistBits3(const uint64_t p[], uint32_t n, uint32_t hist[64]) {
  uint64_t mask1 = 1;
  uint64_t mask2 = 2;
  uint64_t mask3 = 4;
  uint64_t mask4 = 8;
  for (uint64_t i = 0; i < 64; i+=4, mask1 <<= 4, mask2 <<= 4, mask3 <<= 4, mask4 <<= 4) {
    uint64_t count1 = 0;
    uint64_t count2 = 0;
    uint64_t count3 = 0;
    uint64_t count4 = 0;
    for (uint32_t i = 0; i < n; i++) {
      if (p[i] & mask1)
	count1++;
      if (p[i] & mask2)
	count2++;
      if (p[i] & mask3)
	count3++;
      if (p[i] & mask4)
	count4++;
    }
    hist[i] = count1;
    hist[i+1] = count2;
    hist[i+2] = count3;
    hist[i+3] = count4;
    //TODO: vectorize this and do 16 at a time for even more speed
  }
  //  for (int i = 0; i < 64; i++)
  //    cout << hist[i] << '\n';
}


void countHistBits4(const uint64_t p[], uint32_t n, uint32_t hist[64]) {
  uint16_t masks[16] = {1U, 1U<<1, 1U<<2, 1U<<3, 1U<<4, 1U<<5, 1U<<6, 1U<<7,
			1U<<8, 1U<<9, 1U<<10, 1U<<11, 1U<<12, 1U<<13, 1U<<14, 1U<<15};
  __m256i mask = _mm256_load_si256((const __m256i*)&masks[0]);
  __m256i count1 = _mm256_setzero_si256();
  __m256i count2 = _mm256_setzero_si256();
  __m256i count3 = _mm256_setzero_si256();
  __m256i count4 = _mm256_setzero_si256();
  for (uint32_t i = 0; i < n; i++) {
    __m256i v1 = _mm256_set1_epi16(p[i] & 0xFFFF);
    __m256i v2 = _mm256_set1_epi16((p[i] >> 16) & 0xFFFF);
    __m256i v3 = _mm256_set1_epi16((p[i] >> 32) & 0xFFFF);
    __m256i v4 = _mm256_set1_epi16((p[i] >> 48) & 0xFFFF);
    v1 = _mm256_and_si256(v1, mask);
    count1 = _mm256_adds_epi16 (count1, v1);
    v2 = _mm256_and_si256(v2, mask);
    count2 = _mm256_adds_epi16 (count2, v2);
    v3 = _mm256_and_si256(v3, mask);
    count3 = _mm256_adds_epi16 (count3, v3);
    v4 = _mm256_and_si256(v4, mask);
    count4 = _mm256_adds_epi16 (count4, v4);
    //TODO: this needs to compare against zero and count, not just add each number
  }
  _mm256_store_si256((__m256i*)&hist[0], count1);
  _mm256_store_si256((__m256i*)&hist[4], count2);
  _mm256_store_si256((__m256i*)&hist[8], count3);
  _mm256_store_si256((__m256i*)&hist[12], count4);
  //TODO: numbers might exceed 64k, that has to be handled.
}

typedef void (*ArrayFunc)(uint64_t[], uint32_t);
typedef void (*Hist64Func)(const uint64_t[], uint32_t, uint32_t hist[64]);
void bench(const char msg[], ArrayFunc f, uint64_t* p, uint32_t n) {
  clock_t t0 = clock();
  f(p,n);
  clock_t t1 = clock();
  cout << msg << ": " << (t1-t0)*1e-6 << '\n';
}

void bench(const char msg[], Hist64Func f, uint64_t* p, uint32_t n, uint32_t hist[64]) {
clock_t t0 = clock();
 f(p,n, hist);
clock_t t1 = clock();
 cout << msg << ": " << (t1-t0)*1e-6 << '\n';
}

int main() {
  const int n = 10000000;
  uint64_t* p = new uint64_t[n];

  /*
    count how many occurrences of each bit position are 1
    should be about half
  */
  uint32_t histBits[64];

  bench("genRand1: ", genRand1, p, n);
  bench("countHistBits1: ", countHistBits1, p, n, histBits);
  varHistBits(histBits, n);
  bench("countHistBits2: ", countHistBits2, p, n, histBits);
  varHistBits(histBits, n);
  bench("countHistBits1: ", countHistBits1, p, n, histBits);
  varHistBits(histBits, n);
  bench("countHistBits3: ", countHistBits3, p, n, histBits);
  bench("countHistBits4: ", countHistBits3, p, n, histBits);
  
  bench("genRand2: ", genRand2, p, n);
  bench("countHistBits2: ", countHistBits2, p, n, histBits);
  varHistBits(histBits, n);
  bench("countHistBits1: ", countHistBits1, p, n, histBits);
  varHistBits(histBits, n);
  bench("countHistBits2: ", countHistBits2, p, n, histBits);
  varHistBits(histBits, n);

  bench("genRand3: ", genRand3, p, n);
  bench("countHistBits2: ", countHistBits2, p, n, histBits);

  bench("genRand4: ", genRand4, p, n);
  bench("countHistBits2: ", countHistBits2, p, n, histBits);

  varHistBits(histBits, n);
  
  uint32_t hist1[hist_bins] = {0};
  uint32_t hist2[hist_bins] = {0};
  uint32_t hist3[hist_bins] = {0};
  uint32_t hist4[hist_bins] = {0};
  uint32_t hist5[hist_bins] = {0};
  uint32_t hist6[hist_bins] = {0};
  
  for (uint32_t i = 0; i < n; i++) {
    uint64_t m = p[i];
    hist1[m >> 57]++;
    hist2[(m >> 50) & 0x7F]++;
    hist3[(m >> 43) & 0x7F]++;
    hist4[(m >> 36) & 0x7F]++;
    hist5[(m >> 29) & 0x7F]++;
    hist6[(m >> 22) & 0x7F]++;
  }
  // each histogram should have roughly n/hist_bins per bin
  // checking...
  double expected = double(n) / hist_bins;
  displayHist(hist1, expected, n);
  displayHist(hist2, expected, n);
  displayHist(hist3, expected, n);
  displayHist(hist4, expected, n);
  displayHist(hist5, expected, n);
  displayHist(hist6, expected, n);
  {
  Stats stats;
  for (uint32_t i = 0; i < n; i+=2)
    stats.add(p[i], p[i+1]);
  cout << "64 bit correlation: " << stats.corr() << '\n';
  }

  {
    Stats stats;
    for (uint32_t i = 0; i < n; i++)
      stats.add(*(uint32_t*)&p[i], ((uint32_t*)&p[i])[1]);
    cout << "32 bit correlation: " << stats.corr() << '\n';
  }

  delete [] p;
}
