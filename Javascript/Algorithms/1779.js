/**
 * @param {number} x
 * @param {number} y
 * @param {number[][]} points
 * @return {number}
 */
let nearestValidPoint = (x, y, points) => {
    let prev_min = 10 << 10,
        dst = prev_min,
        index = -1;
    points.forEach((pair, idx) => {
        let [xi, yi] = pair;
        if (xi == x)
            dst = yi - y;
        else if (yi == y)
            dst = xi - x;

        dst = dst < 0 ? -dst : dst;
        if (dst < prev_min) {
            prev_min = dst;
            index = idx;
        }
    });
    return index;
};