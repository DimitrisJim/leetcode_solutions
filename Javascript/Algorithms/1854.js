/**
 * @param {number[][]} logs
 * @return {number}
 */
var maximumPopulation = function(logs) {
  // hold the counts for each year. Year can be found by
  const counts = Array(101).fill(0);

  // Fill in counts for each range.
  let max = 0;
  for (let [start, end] of logs) {
    // subtract 1950 to go from [1950, 2050] range
    // to [0, 100] range. (both are inclusive).
    for (let i = start - 1950; i < end - 1950; i++) {
      counts[i]++;
      if (max < counts[i]) max = counts[i];
    }
  }
  // find min index in counts with value == max.
  let index = 0;
  for (let i = 0; i < counts.length; i++) {
    if (counts[i] == max) {
      index = i;
      break;
    }
  }
  // from index => years.
  return index + 1950;
};