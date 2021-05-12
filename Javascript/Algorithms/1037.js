/**
 * @param {number[][]} points
 * @return {boolean}
 */
var isBoomerang = function(points) {
  const slope = (p1, p2) => {
    if (p2[0] == p1[0]) return p2[1] - p1[1];
    return (p2[1] - p1[1]) / (p2[0] - p1[0]);
  };

  const [a, b, c] = points;
  if ((a[0] == b[0] && b[0] == c[0]) || (a[1] == b[1] && b[1] == c[1])) {
    return false;
  }
  // a == b?
  if (a[0] == b[0] && a[1] == b[1]) return false;
  // a == c?
  if (a[0] == c[0] && a[1] == c[1]) return false;
  // b == c?
  if (b[0] == c[0] && b[1] == c[1]) return false;

  const s1 = slope(a, b), s2 = slope(b, c), s3 = slope(a, c);
  return !(s1 == s2 && s2 == s3);
};