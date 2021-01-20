let distanceBetweenBusStops = (distance, start, destination) => {
    // sum to start, sum to dest, sum to end
    let sts = 0, std = 0, ste = 0, idx=1;
    distance.forEach((val) => {
        if (idx <= start)
            sts += val;
        if (idx <= destination)
            std += val;
        ste += val;
        idx++;
    });
    // Calculate differences.
    let diff = start > destination ? sts - std: std - sts,
        diff2 = ste - diff;
    return diff < diff2 ? diff: diff2;    
};
