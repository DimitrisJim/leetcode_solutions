// 32 bit ints (2's complement assuming)
#define ABS(x) ((x >> 31) ^ x) - (x >> 31)

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    register int steps = 0;
    int sx, sy, dx, dy, diff_x, diff_y;
    for(int i = 0; i < pointsSize - 1; i++){
        sx = points[i][0];
        sy = points[i][1];
        dx = points[i+1][0];
        dy = points[i+1][1];
        // Move diagonally first.
        if ((sx ^ dx) || (sy ^ dy)){
            diff_x = dx - sx;
            diff_y = dy - sy;
            int abs_diff_x = ABS(diff_x);
            int abs_diff_y = ABS(diff_y);
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
        if ((sy ^ dy) && !(sx ^ dx)){
            diff_y = dy - sy;
            sy += diff_y;
            steps += ABS(diff_y);
        // If not, horizontically (x-axis.)
        } else {
            diff_x = dx - sx;
            sx += diff_x;
            steps += ABS(diff_x);
        }
    }
    return steps;
}
