let totalMoney = n => {
    const weeks = Math.floor(n / 7), days = n % 7;
    let partial = 0, week_sum = 28;
    for(let i = 0; i < weeks; i++){
        partial += week_sum;
        week_sum += 7;
    }
    for(let i = 1; i <= days; i++)
        partial += weeks + i;
    return partial;
};
