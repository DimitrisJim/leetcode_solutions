int cmpint(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    
    return (x > y) - (x < y);
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize){
    qsort(seats, seatsSize, sizeof(*seats), cmpint);
    qsort(students, studentsSize, sizeof(*students), cmpint);
    
    int moves = 0;
    for (int i = 0; i < seatsSize; i++) {
        int diff = students[i] - seats[i];
        moves += diff > 0 ? diff: -diff;
    }
    return moves;
}