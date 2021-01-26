let groupThePeople = groupSizes => {
    const d = new Map,
          result = [],
          length = groupSizes.length;
    
    groupSizes.forEach((group_i, idx) => {
        // if group size is one, just push to
        // result.
        if (group_i == 1){
            result.push([idx]);
        } else {
            let group = d.get(group_i);
            // no group -> add group to d.
            if (!group) {
                d.set(group_i, [idx]);
            // add group if filled, else push value to group.
            } else {
                if (group.length == group_i){
                    result.push(group);
                    d.set(group_i, [idx]);
                } else {
                    group.push(idx)
                }
            }
        }
    });
    
    // Add any remaining groups to result.
    result.push(...d.values());
    return result;
};
