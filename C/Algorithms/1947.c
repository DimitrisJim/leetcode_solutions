#define ABS(x) (x) > 0 ? (x) : -(x);

int minTimeToType(char *word) {
  int prev = 97; // 'a'
  int result = 0;
  while (*word) {
    int next = *word++;
    int dst = ABS(next - prev);
    result += (dst > 13 ? 26 - dst : dst) + 1;
    prev = next;
  }
  return result;
}