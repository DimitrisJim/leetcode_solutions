int commonFactors(int a, int b){
    if (a == 1 || b == 1)
        return 1;
    int fractions = 1;
    int max, min;
    if (a > b)
        max = a, min = b;
    else
        max = b, min = a;
    if (max % min == 0)
        fractions++;
    
    for(int i = 2; i < (min / 2) + 1; i++){
        if (max % i == 0 && min % i == 0)
            fractions++;
    }
    return fractions;
}