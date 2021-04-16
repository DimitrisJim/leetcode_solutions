/**
 * @param {string} a
 * @param {string} b
 * @return {boolean}
 */
let buddyStrings = (a, b) => {
  // Return early on length mismatch.
  if (a.length != b.length) return false;

  // Find indices where strings differ.
  const diffs = [];
  for (let i = 0; i < a.length; i++) {
    if (a[i] != b[i]) diffs.push(i);
  }

  // If we have more than 2 indices where they differ, can't swap.
  if (diffs.length > 2)
    return false;
  else if (diffs.length == 2) {
    // See if characters in indices are the same.
    const first = diffs[0], second = diffs[1];
    if ((a[first] == b[second]) && (a[second] == b[first])) return true;
    return false;
  } else if (diffs.length == 1) {
    return false;
  } else {
    // No diffs. This leads to two cases:
    //  - a == b and both a, b have unique chars => we can't do any swaps.
    //  - a == b and a and b have duplicate chars => swap duplicates.
    // We can use sets to see if dups exist and if so return True.
    const sa = new Set(a), sb = new Set(b);
    return sa.size < a.length && sb.size < b.length;
  }
};