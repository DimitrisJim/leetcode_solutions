/**
 * @param {number[][]} points
 * @return {number}
 */
let maxWidthOfVerticalArea = points => {
    // Remove points with the same x.
    const r_points = [];
    points.forEach(p => r_points.push(p[0]));

    const length = r_points.length;
    // Sort and find max diff.
    const sorter = (a, b) => b - a,
          max = Math.max;
    let max_diff = 0;
    r_points.sort(sorter);
    for (let i = 0; i < length - 1; i++)
        max_diff = max(max_diff, r_points[i] - r_points[i+1]);
    return max_diff;
};
