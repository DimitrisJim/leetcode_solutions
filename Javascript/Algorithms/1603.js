/**
 * @param {number} big
 * @param {number} medium
 * @param {number} small
 */
var ParkingSystem = function(big, medium, small) {
    this.big = big;
    this.medium = medium;
    this.small = small;
};

/** 
 * @param {number} carType
 * @return {boolean}
 */
ParkingSystem.prototype.addCar = function(carType) {
    if (carType == 1){
        if (this.big == 0)
            return false;
        this.big -= 1;
        return true;
    }
    if (carType == 2){
        if (this.medium == 0)
            return false;
        this.medium -= 1;
        return true;
    } 
    if (carType == 3){
        if (this.small == 0)
            return false;
        this.small -= 1;
        return true;
    }
};

/** 
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new ParkingSystem(big, medium, small)
 * var param_1 = obj.addCar(carType)
 */
