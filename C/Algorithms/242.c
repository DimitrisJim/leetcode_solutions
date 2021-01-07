#include <stdbool.h>

// Though overflowing for unsigned is well defined,
// this is hacky as hell and I'm not even sure if
// it works for all cases really. (won't even think
// about unicode.)
bool isAnagram(char *s, char *t) {
  unsigned x1 = 1, x2 = 1;
  int xr1 = 0, xr2 = 0;

  // Two pronged attack, get the cumulative (with a lot
  // of overflow) mult of all characters while also xor'ing
  // them (common xor trick.)
  while (*s && *t) {
    x1 *= *s, xr1 ^= *s++;
    x2 *= *t, xr2 ^= *t++;
  }
  // bail if lengths are different.
  if (*t || *s)
    return false;

  // xor'ing filters some stuff (different characters, mostly),
  // mults filter others (same character repeated, sequences such
  // as ['uiiiiaadaa', 'doooou']).
  return (x1 == x2) && (xr1 == xr2);
}
