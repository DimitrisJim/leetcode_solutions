let countGoodRectangles = rectangles => {
    let max = 0, count = 0;
    // Note: nice unpacking!
    rectangles.forEach(([a, b])=> {
        let m = a > b ? b: a;
        if (m == max)
            count++;
        else if (m > max){
            count = 1;
            max = m;
        }
    });
    return count;
};
