/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function(points) {
    let steps = 0;
    let sx, sy, dx, dy, diff_x, diff_y;
    const len = points.length - 1;
    const abs = Math.abs;
    for(let i = 0; i < len; i++){
        sx = points[i][0];
        sy = points[i][1];
        dx = points[i+1][0];
        dy = points[i+1][1];
        // Move diagonally first.
        if ((sx != dx) || (sy != dy)){
            diff_x = dx - sx;
            diff_y = dy - sy;
            const abs_diff_x = abs(diff_x);
            const abs_diff_y = abs(diff_y);
            if (abs_diff_x < abs_diff_y){
                sx += diff_x;
                sy += diff_y > 0 ? abs_diff_x : -abs_diff_x;
                steps += abs_diff_x;
            } else {
                sy += diff_y;
                sx += diff_x > 0 ? abs_diff_y : -abs_diff_y;
                steps += abs_diff_y;
            }
        }
        // Then vertically (y-axis)
        if ((sy != dy) && (sx == dx)){
            diff_y = dy - sy;
            sy += diff_y;
            steps += abs(diff_y);
        // If not, horizontically (x-axis.)
        } else {
            diff_x = dx - sx;
            sx += diff_x;
            steps += abs(diff_x);
        }
    }
    return steps;
};
