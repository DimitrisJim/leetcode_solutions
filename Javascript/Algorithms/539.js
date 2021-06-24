/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
  // Can use a set to hold values. This way we can bail early
  // if we encounter a duplicate.
  let timepoints = new Set;
  for (let d of timePoints) {
    let [h, m] = d.split(':').map(x => parseInt(x)),
            v = (h > 0      ? h :
                     m == 0 ? 0 :
                              24) *
            60 +
        m;
    if (timepoints.has(v)) return 0;
    timepoints.add(v);
  }
  timepoints = [...timepoints];
  timepoints.sort((x, y) => x - y);

  let min = Math.min, min_diff = 2400;
  for (let i = 0; i < timepoints.length - 1; i++)
    min_diff = min(min_diff, timepoints[i + 1] - timepoints[i]);

  // check min time + 1440 (24 * 60) - max_time to see if we have a smaller
  // value on the edges.
  min_diff = min(min_diff, timepoints[0] + 1440 - timepoints.pop());
  return min_diff;
};