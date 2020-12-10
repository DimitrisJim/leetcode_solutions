let calPoints = ops => {
    
    const handle_op = (op, score) => {
        let length = score.length;
        if (op == 'C'){
            score.pop();
        } else if (op == '+') {
            score.push(score[length-1] + score[length-2]);
        } else if (op == 'D') {
            score.push(score[length-1] * 2);
        } else {
            score.push(parseInt(op));
        }
    },
          sum = (acc, val) => acc + val;
    
    const score = [parseInt(ops[0])],
          length = ops.length;
    let i = 1;
    while (i < length - 1){
        let op1 = ops[i];
        if (ops[i+1] == 'C' && op1 != 'C'){
            i += 2;
            continue;
        }
        handle_op(op1, score);
        i++;
    }
    if (i < length){
        handle_op(ops[length-1], score);
    }
    return score.reduce(sum);
};
