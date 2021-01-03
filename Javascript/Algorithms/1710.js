let maximumUnits = (boxTypes, truckSize) => {
    boxTypes.sort((a, b) => b[1] - a[1]);
    
    let length = boxTypes.length,
        count = 0, i = 0;
    
    while (truckSize && i < length){
        let [num_b, num_u] = boxTypes[i++];
        if (num_b < truckSize){
            count += num_b * num_u;
            truckSize -= num_b;
        } else {
            // Can't fit more than num_b boxes, 
            // use truckSize boxes:
            return count + truckSize * num_u;
        }
    }
    return count;
};
