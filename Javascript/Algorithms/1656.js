/**
 * @param {number} n
 */
var OrderedStream = function(n) {
    this.ptr = 1;
    this.values = new Map;
};

/** 
 * @param {number} id 
 * @param {string} value
 * @return {string[]}
 */
OrderedStream.prototype.insert = function(id, value) {
    let res = [];
    this.values.set(id, value);
    while (true){
        let val = this.values.get(this.ptr);
        if (!val){
            break;
        }
        res.push(val);
        this.ptr++;
    }
    return res;
};
