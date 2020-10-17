/**
 * @param {string} S
 * @return {string}
 */
let removeOuterParentheses = S => {
    const res = [];
    let depth = 0;
    for (const c of S){
        if (c == '('){
            if (depth ^ 0){
                res.push(c);
            }
            depth++;
        } else {
            depth--;
            if (depth ^ 0){
                res.push(c);
            }
        }
    }
    return res.join("");
};
