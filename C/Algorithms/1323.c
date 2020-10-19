int maximum69Number (int num){
    if ((num == 6) || (num == 9))
        return 9;
    if ((num == 99) || (num == 999) || (num == 9999))
        return num;
    
    // Find num of digits
    int digits = 0, temp = num, div, d = 1;
    for(; temp; temp /= 10, digits++);
    // Create our divisor
    while (--digits){
        d *= 10;
    } 
    d *= 9;
    // Divide until you can then return.
    div = num / d;
    temp = num % d;
    while (div == 1){
        d /= 10;
        div = temp / d;
        temp = temp % d;
    }
    return num + (d / 3);
        
}
