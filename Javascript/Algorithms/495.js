/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function(timeSeries, duration) {
  if (duration == 0) return 0;
  if (duration == 1) return (new Set(timeSeries)).size;

  let seconds = 0;
  for (let i = 1; i < timeSeries.length; i++) {
    let a1 = timeSeries[i - 1], a2 = timeSeries[i];
    if (a1 != a2) seconds += a2 < (a1 + duration) ? a2 - a1 : duration;
  }
  // add duration for final element.
  return seconds + duration;
};