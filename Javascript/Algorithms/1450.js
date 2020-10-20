// Wastefull ternary (with 0 if false.)
// Weirdly enough, had the best execution among others (once)
let busyStudent = (startTime, endTime, queryTime) => {
    let count = 0;
    startTime.forEach((x, i) => 
        (x <= queryTime) ? (queryTime <= endTime[i] ? count++ : 0): 0
    );
    return count;
};

// Using boolean ops, thanks! 
// @ https://stackoverflow.com/a/40940678/4952130
let busyStudent1 = (startTime, endTime, queryTime) => {
    let count = 0;
    startTime.forEach((x, i) => 
        (x > queryTime) || (queryTime > endTime[i]) || count++
    );
    return count;
};

// Typical for loop:
let busyStudent3 = (startTime, endTime, queryTime) => {
    let count = 0, len = startTime.length;
    for(let i = 0; i < len; i++){
        if (startTime[i] <= queryTime){
            if (queryTime <= endTime[i]){
                count++;
            }
        }
    }
    return count;
};
