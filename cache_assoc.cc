#include <iostream>
#include <cmath>
#include <x86intrin.h>
#include <time.h>

int main() {
  long before, after;
  long n = pow(2, 21);

  time_t bt, at;

  char *a = (char *)malloc(n);

  before = _rdtsc();
  time(&bt);
  for (int i = 0; i < n; i = i + 256) {
    a[i]++;
  }
  time(&at);
  after = _rdtsc();
  std::cout << "256 Loop " << after - before << "\n";
  std::cout << "256 Loop Time " << difftime(at, bt) << "\n";

  before = _rdtsc();
  time(&bt);
  for (int i = 0; i < n; i = i + 257) {
    a[i]++;
  }
  time(&at);
  after = _rdtsc();
  std::cout << "257 Loop " << after - before << "\n";
  std::cout << "257 Loop Time " << difftime(at, bt) << "\n";

  before = _rdtsc();
  time(&bt);
  for (int i = 0; i < n; i = i + 255) {
    a[i]++;
  }
  time(&at);
  after = _rdtsc();
  std::cout << "255 Loop " << after - before << "\n";
  std::cout << "255 Loop Time " << difftime(at, bt) << "\n";

  return 0;
}
