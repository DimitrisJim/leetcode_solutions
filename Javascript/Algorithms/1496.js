// No tuples in JS so just add them as strings in the points set.
let isPathCrossing = path => {
    let points = new Set(["00"]), 
        [i, j] = [0, 0];

    for (let d of path) {
        if (d == 'W'){
            j++;
        } else if (d == 'E'){
            j--;
        } else if (d == 'N'){
            i++; 
        } else {
            i--;
        }
        if (points.has(`${j}${i}`)){
            return true;
        }
        points.add(`${j}${i}`);
    }
    return false;
};
