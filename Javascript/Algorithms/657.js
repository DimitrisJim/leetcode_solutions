/**
 * @param {string} moves
 * @return {boolean}
 */
let judgeCircle = moves => {
    let u = d = l = r = 0;
    for (let c of moves){
        switch(c){
            case 'L': l++; break;
            case 'R': r++; break;
            case 'U': u++; break;
            case 'D': d++; break;
        }
    }
    return (u == d) && (l == r);
};
