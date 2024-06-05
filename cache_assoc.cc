#include <iostream>
#include <cmath>
#include <x86intrin.h>

int main() {
  long before, after;
  long n = pow(2, 21);

  char *a = (char *)malloc(n);

  before = _rdtsc();
  for (int i = 0; i < n; i = i + 256) {
    a[i]++;
  }
  after = _rdtsc();
  std::cout << "256 Loop " << after - before << "\n";

  before = _rdtsc();
  for (int i = 0; i < n; i = i + 257) {
    a[i]++;
  }
  after = _rdtsc();
  std::cout << "257 Loop " << after - before << "\n";

  return 0;
}
