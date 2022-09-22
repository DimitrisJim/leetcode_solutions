#define RED 1
#define BLUE 2
#define GREEN 4
#define RODS 10

int countPoints(char * rings){
    int *rods = calloc(RODS, sizeof(int));
    
    while (*rings) {
        char color = *rings++;
        int rod = *rings++ - '0', b = 0;
        
        if (color == 'R') b = RED;
        else if (color == 'G') b = GREEN;
        else b = BLUE;
        
        rods[rod] |= b;
    }
    
    int count = 0;
    for (int i = 0; i < RODS; i++) {
        if (rods[i] == (RED | BLUE | GREEN)) {
            count++;
        }
    }
    return count;
}