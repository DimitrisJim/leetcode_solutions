let maxNumberOfBalloons = (text) => {
    const counter = new Map,
          str = "balloon";
    // Fill counter up.
    for (let c of text){
        let value = counter.get(c);
        value == undefined ? counter.set(c, 1) : counter.set(c, value + 1);
    }
    // Check how many balloons we have.
    let times = 0;
    while (true){
        for (let c of str){
            let value = counter.get(c);
            if (value == 0 || value == undefined){
                return times;
            } else {
                counter.set(c, value-1);
            }
        }
        times++;
    }
};
