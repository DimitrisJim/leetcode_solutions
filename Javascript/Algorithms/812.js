/**
 * @param {number[][]} points
 * @return {number}
 */
let largestTriangleArea = points => {
    let max = -1;
    
    // Go through triplets:
    const length = points.length,
          imax = length - 3 + 1,
          jmax = length - 3 + 2,
          kmax = length;
    for(let i = 0; i < imax; i++){
        for (let j = i+1; j < jmax; j++){
            for(let k = j+1; k < kmax; k++){
                const p1 = points[i], p2 = points[j], p3 = points[k],
                      x1 = p1[0], x2 = p2[0], x3 = p3[0],
                      y1 = p1[1], y2 = p2[1], y3 = p3[1];

                let area = 0.5 * (x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3);
                area = area > 0 ? area: -area;
                if (area > max)
                    max = area;
            }
        }
    }
    return max;
};
