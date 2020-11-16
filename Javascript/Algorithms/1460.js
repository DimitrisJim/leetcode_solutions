var canBeEqual = (target, arr) => {
    target.sort()
    arr.sort()
    const len = arr.length
    for(let i = 0; i < len; i++){
        if (arr[i] != target[i]){
            return false;
        }
    }
    return true;
};
