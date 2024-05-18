## Cost of operations
- memory alloc是 cN，和大小有关；
- string concat：s + t，也是cN的时间；
- 其余基本都是常数开销

## 常见的复杂度
- 1 + 2 + ... + N ～ 相当于是对f(x) = x积分，结果就是N^2
- 1^k + 2^k + ... + N^k ~ 相当于是对f(x) = x^k积分，结果就是N^(k+1)
- 1 + 1/2 + ... + 1/N ~ 相当于是对f(x) = 1/x积分，结果就是lg N
  
## Order of growth
- 1, lg N, N, N*lg N, N^2, N^3, 2^N

## type of analyses
- Best case
- Worst case
- Average case

## example
- three sum
- binary search
