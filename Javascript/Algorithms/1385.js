ram {number[]} arr1
 * @param {number[]} arr2
 * @param {number} d
 * @return {number}
 */
let findTheDistanceValue = (arr1, arr2, d) => {
    let count =  0;
    arr1.forEach(el => {
        const top = el + d,
            bottom = el - d;
        for(let el2 of arr2){
            if ((top >= el2) && (el2 >= bottom)){
                count--;
                break;
            }
        }
        count++;
    });
    return count;
};
