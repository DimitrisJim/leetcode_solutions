let slowestKey = (releaseTimes, keysPressed) => {
    const length = releaseTimes.length;
    let max = releaseTimes[0],
        max_indices = [0];
    
    for(let i = 1; i < length; i++){
        let diff = releaseTimes[i] - releaseTimes[i-1];
        if (diff > max){
            max_indices = [i];
            max = diff;
        } else if (diff == max){
            max_indices.push(i);
        }
    }
    let maxC = keysPressed[max_indices[0]],
        mlength = max_indices.length;
    for(let i = 1; i < mlength; i++){
        let c = keysPressed[max_indices[i]];
        if (c > maxC){
            maxC = c;
        }
    }
    return maxC;
};
