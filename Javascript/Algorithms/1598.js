let minOperations = logs => {
    let in_main = 1, depth = 0;
    logs.forEach(log => {
        if (log == "../") {
            if (in_main == 0){
                depth--;
                if (!depth)
                    in_main = 1;
            }
        }
        else if (log == "./"){
            ;    // Do nothing
        } else {
            depth++;
            if (in_main)
                in_main ^= 1;
        }
    });
    return depth;
};
