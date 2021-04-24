// Translation from C approach.
let countSegments = function(s) {
  return s.split(' ').filter(x => x != '').length;
};

// Translation from C approach.
let countSegments = function(s) {
  const length = s.length;
  if (length == 0) return 0;
  let i = 0, segments = (s[0] == ' ' ? 0 : 1);
  while (i < length) {
    if (s[i++] == ' ') {
      while (s[i] == ' ') i++;
      if (i >= length) break;
      segments++;
    }
  }
  return segments;
};