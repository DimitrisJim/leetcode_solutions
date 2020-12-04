let allCellsDistOrder = (R, C, r0, c0) => {
    const result = [[r0, c0]],
        indices = [],
        sorter = (x, y) => (x[0] + x[1]) - (y[0] + y[1]);
        
    for (let i = 0; i <= Math.max(R-r0, r0); i++){
        for(let j = 0; j <= Math.max(C-c0, c0); j++){
            indices.push([i, j]);
        }
    }
    indices.sort(sorter);

    const len = indices.length;
    for(let k = 1; k < len; k++){
        let [i, j] = indices[k];
        let [rpi, rmi, cpj, cmj] = [r0 + i, r0 - i, c0 + j, c0 - j];
        if (rmi >= 0) {
            if (cmj >= 0) {
                result.push([rmi, cmj]);
            }
            if (j > 0 && cpj < C) {
                result.push([rmi, cpj]);
            }
        }
        if (rpi < R && i > 0) {
            if (cpj < C) {
                result.push([rpi, cpj]);
            }
            if (j > 0 && cmj >= 0) {
                result.push([rpi, cmj]);
            }
        }
    }
    return result;
};
