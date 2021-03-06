#include "longlong.h"

extern void __bdiv ();

long long 
__umoddi3 (u, v)
     long long u, v;
{
  unsigned long a[2][2], b[2], q[2], r[2];
  long_long w;
  long_long uu, vv;

  uu.ll = u;
  vv.ll = v;

  a[HIGH][HIGH] = 0;
  a[HIGH][LOW] = 0;
  a[LOW][HIGH] = uu.s.high;
  a[LOW][LOW] = uu.s.low;
  b[HIGH] = vv.s.high;
  b[LOW] = vv.s.low;

  __bdiv (a, b, q, r, sizeof a, sizeof b);

  w.s.high = r[HIGH];
  w.s.low = r[LOW];
  return w.ll;
}
