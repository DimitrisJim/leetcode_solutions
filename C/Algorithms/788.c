#include <math.h>

// Ammounts and mirrors can be precalculated
// (by a script) based on p.
static int power = 3;
int ammounts[] = {0, 4, 40, 316};
int mirrors[] = {1,   8,   10,  11,  18,  80,  81,  88,  100,
                 101, 108, 110, 111, 118, 180, 181, 188, 800,
                 801, 808, 810, 811, 818, 880, 881, 888};
int mirrorSize = sizeof(mirrors) / sizeof(mirrors[0]);
// mults stay the same independent from p.
int mults[10][2] = {
    {1, 0}, {2, 0}, {2, 1}, {2, 1}, {2, 1},
    {2, 2}, {2, 3}, {2, 3}, {3, 3}, {3, 4},
};

// Include any mirrored rotations.
inline int include_mirror_rotations(int j) {
  int count = 1;
  for (int i = 0; i < mirrorSize; i++) {
    if (j < mirrors[i])
      break;
    count++;
  }
  return count;
}

inline int add_until_previous(int v, int p) {
  int *mult = mults[v - 1];
  int i = mult[0], j = mult[1];
  int prev = ammounts[p];
  return i * prev + j * (prev + pow(3, p));
}

int rotatedDigits(int N) {
  int div = pow(10, power), good_numbers = 0, p = power;
  while (N) {
    int quot = N / div;
    N %= div;
    div /= 10;

    if (quot) {
      good_numbers += add_until_previous(quot, p);

      if (quot == 3 || quot == 4 || quot == 7)
        return good_numbers;
      else if (quot == 2 || quot == 5 || quot == 6 || quot == 9)
        good_numbers += include_mirror_rotations(N);
    }
    p--;
  }

  return good_numbers;
}
