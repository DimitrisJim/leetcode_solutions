let interpret = s => {
    let result = [], 
        length = s.length,
        i = 0;
    
        while (i < length) {
            // () case
            if ((s[i] == '(') && (s[i+1] == ')')){
                result.push('o');
                i = i + 2;
            }
            else if (s[i] == 'G'){
                result.push('G');
                i++;
            }
            // case (al)
            else {
                result.push('al');
                i = i + 4; 
            }
        }
        return result.join("");
};
