// Classic for-loop through list.
int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime){
    int count = 0;
    for(int i = 0; i < startTimeSize; i++){
        if (startTime[i] <= queryTime){
            if (queryTime <= endTime[i])
                count++;
        }
    }
    return count;
}

// Pointer arithmetic version.
int busyStudent2(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime){
    unsigned count = 0, i = 0;
    // Note: startTime == endTime.
    while (i < startTimeSize){
        if (*(startTime + i) <= queryTime){
            if (queryTime <= *(endTime + i))
                count++;
        }
        i++;
    }
    return count;
}
