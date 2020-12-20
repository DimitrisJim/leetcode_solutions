let fizzBuzz = n => {
    const floor = Math.floor,
          res = Array(n);
    n++;
    for (let i = 1; i < n; i++){
        let [r, m] = [floor(i/3), i % 3];
        if (m == 0){
            res[i-1] = r % 5? "Fizz": "FizzBuzz";
        } else { 
            res[i-1] = i % 5? `${i}`: "Buzz";
        }
    }
    return res;
};
