let maxScore = s => {
    let l = 1, end = s.length - 1,
        max_ = (s.match(/1/g) || []).length + (s[0] == '1'? -1: 1),
        tmp = max_;
    while (l < end){
        tmp += s[l++] == '0'? 1 : -1;
        if (tmp > max_){
            max_ = tmp
        }
    }
    return max_
};
