int fib(int N) {
      if(N == 0)  return 0;
      if(N == 1)  return 1;
      return fib(N-1) + fib(N-2);
  }

int fib(int N) {
      if(N < 2)
          return N;
      int memo[N+1];
      memo[0] = 0;
      memo[1] = 1;
      for(int i=2; i<=N; i++)
          memo[i] = memo[i-1] + memo[i-2];
      return memo[N];
  }

int fib(int N) {
      if(N < 2) 
          return N;
    int a = 0, b = 1, c = 0;
      for(int i = 1; i < N; i++)
      {
          c = a + b;
          a = b;
          b = c;
      }
      return c;
  }

int fib(int N) {
    double phi = (sqrt(5) + 1) / 2;     
    return round(pow(phi, N) / sqrt(5));
}
