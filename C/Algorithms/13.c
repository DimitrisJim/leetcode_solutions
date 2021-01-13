inline int is_special(char *s) {
  char next = *(s + 1);
  if (*s == 'I') {
    if (next == 'V' || next == 'X')
      return 1;
  } else if (*s == 'X') {
    if (next == 'L' || next == 'C')
      return 1;
  } else if (*s == 'C') {
    if (next == 'D' || next == 'M')
      return 1;
  }
  return 0;
}

inline int rtoi(char r) {
  switch (r) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }
  return 0;
}

int romanToInt(char *s) {
  int n = 0;
  while (*s && *(s + 1)) {
    if (is_special(s)) {
      n = n - rtoi(*s) + rtoi(*(s + 1));
      s = s + 2;
      continue;
    }
    n += rtoi(*s);
    s++;
  }
  return *s ? n + rtoi(*s) : n;
}
