int countOperations(int num1, int num2){
    int ops = 0;
    while (num1 > 1 && num2 > 1) {
        if (num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
        ops++;
    }
    if (num1 == 0 || num2 == 0)
        return ops;
    return ops + num2 + num1 - 1;
}