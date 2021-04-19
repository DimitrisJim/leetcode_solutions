/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
  /**
   * @param {integer} n Total versions
   * @return {integer} The first bad version
   */
  const floor = Math.floor;
  return n => {
    let start = 0, end = n;
    while (end - start != 1) {
      let mid = floor((start + end) / 2);
      if (isBadVersion(mid))
        end = mid;
      else
        start = mid;
    }
    return end;
  };
};