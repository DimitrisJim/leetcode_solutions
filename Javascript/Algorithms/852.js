/**
 * @param {number[]} arr
 * @return {number}
 */
var peakIndexInMountainArray = function(arr) {
    let i = 0, j = arr.length, floor = Math.floor;
    let m = floor((j + i) / 2);
    while (true) {
        let mid = arr[m];
        if (arr[m+1] > mid){
            i = m + 1;
        } else if (arr[m - 1] > mid){
            j = m - 1;
        } else {
            return m;
        }
        m = floor((i + j) / 2);
    }
};
