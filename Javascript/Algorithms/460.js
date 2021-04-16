/**
 * @param {string} s
 * @return {number}
 */
let minOperations = s => {
  const count_changes = (s, expected) => {
    let changes = 0;
    for (let c of s) {
      if (c == expected) changes++;
      expected = expected == '0' ? '1' : '0';
    }
    return changes;
  };

  return Math.min(count_changes(s, '0'), count_changes(s, '1'));
};