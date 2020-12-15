var nextGreaterElement = (nums1, nums2) => {
    const result = Array(nums1.length).fill(-1),
          seen = new Set,
          indices = new Map;
    
    // Populate the map (el -> index)
    nums1.forEach((x, i) => {
        indices.set(x, i);
    });
    
    nums2.forEach(i => {
        // I think JS doesn't mind if you remove
        // elements from set you're iterating.
        for (let k of seen){
            if (i > k){
                result[indices.get(k)] = i;
                seen.delete(k);
            }
        }
        // Keep it in seen if it's in nums1.
        if (indices.has(i)){
            seen.add(i);
        }
    });
    return result;
};
