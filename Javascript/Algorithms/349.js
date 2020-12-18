let intersection = (nums1, nums2) => {
    const h1 = new Set(nums1),
          h2 = new Set(nums2),
          res = [];
    
    // No set.intersection, do it yourself.
    let [min, max] = h1.length < h2.length? [h1, h2] : [h2, h1];
    for (let i of min){
        if (max.has(i)){
            res.push(i);
        }
    }
    return res;
};
