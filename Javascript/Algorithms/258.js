let addDigits = (num) => {
    if (!num)
        return num;
    let res = num % 9;
    return res ? res: 9;
};
