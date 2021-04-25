let sumBase = function(n, k) {
  let s = 0;
  const floor = Math.floor;
  while (n >= k) {
    let r = n % k;
    n = floor(n / k);
    s += r;
  }
  return s + n;
};