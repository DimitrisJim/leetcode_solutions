


typedef struct {
    unsigned int big;
    unsigned int medium;
    unsigned int small;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *p = (ParkingSystem *)malloc(sizeof(ParkingSystem));
    p->big = big;
    p->small = small;
    p->medium = medium;
    
    return p;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    int val;
    if (carType == 1){
        val = obj->big;
        if (val == 0)
            return false;
        obj->big -= 1;
        return true;
   }else if (carType == 2){
        val = obj->medium;
        if (val == 0)
            return false;
        obj->medium -= 1;
        return true;
   } else {
        val = obj->small;
        if (val == 0)
            return false;
        obj->small -= 1;
        return true;
    }
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/
