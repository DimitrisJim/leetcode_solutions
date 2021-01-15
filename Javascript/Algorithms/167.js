let twoSum = (numbers, target) => {
    let i = 0, j = numbers.length - 1;
    while (i < j){
        const ts = numbers[i] + numbers[j];
        if (ts == target){
            break;
        }
        ts > target? j-- : i++;
    }
    return [i+1, j+1];
};
