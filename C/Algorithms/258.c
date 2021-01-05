int addDigits(int num){
    if (!num)
        return num;
    int res = num % 9;
    return res ? res: 9;
}
