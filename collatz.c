#define FUNBOD                                                                 \
  {                                                                            \
    long long n = x & 1 ? x * 3 + 1 : x / 2;                                   \
    return 1 >= n ? 1 : funs[n % funlen](n);                                   \
  }

// Macro system for recursively expanding concatenated names into an X-table
// clang-format off
#define N1(X,f) X(f)
#define N2(X,f) N1(X,f##0) N1(X,f##1) N1(X,f##2) N1(X,f##3) N1(X,f##4) N1(X,f##5) N1(X,f##6) N1(X,f##7) N1(X,f##8) N1(X,f##9)
#define N3(X,f) N2(X,f##0) N2(X,f##1) N2(X,f##2) N2(X,f##3) N2(X,f##4) N2(X,f##5) N2(X,f##6) N2(X,f##7) N2(X,f##8) N2(X,f##9)
#define C(X,N) N(X,f0) N(X,f1) N(X,f2) N(X,f3) N(X,f4) N(X,f5) N(X,f6) N(X,f7) N(X,f8) N(X,f9)
// clang-format on

// X-table; use something like gcc -E collatz.c to see how this works :)
#define COLLATZ(X) C(X, N3)
#define DECL(f) long long f(long long);
#define NAME(f) f,
#define DEFN(f) long long f(long long x) FUNBOD;

// Declare function prototypes
COLLATZ(DECL)

// Define function lookup table
long long (*funs[])(long long) = {COLLATZ(NAME)};
const int funlen = 1000;

// Define the functions
COLLATZ(DEFN)

int main() {
  for (int i = 0; ; i++) {
    f000(i);
    if (i > 100)
      i = 1;
  }
  return 0;
}
