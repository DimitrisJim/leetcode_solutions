/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
let relativeSortArray = (arr1, arr2) => {
    // Create mapping for ordering.
    const order = new Map;
    arr2.forEach((value, index) => {
        order.set(value, index);
    });

	// Sorting function (sort based on ordering.)    
    const sorter = (a, b) => {
        a = order.has(a) ? order.get(a) : (a + 1000);
        b = order.has(b) ? order.get(b) : (b + 1000);
        return a - b;
    };
    arr1.sort(sorter);
    return arr1;
};
