let sumOfUnique = nums => {
    const seen = new Set,
          unique = new Set;
    
    nums.forEach(num  => {
        if (seen.has(num)){
            if (unique.has(num))
                unique.delete(num)
        } else {
            seen.add(num);
            unique.add(num);
        }
    });
    let sum = 0;
    unique.forEach(v => sum += v);
    return sum;
};
