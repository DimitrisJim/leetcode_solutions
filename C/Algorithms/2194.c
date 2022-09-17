/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char* digits = "0123456789";

char ** cellsInRange(char * s, int* returnSize){
    int c1 = s[0], r1 = s[1] - '0', c2 = s[3], r2 = s[4] - '0';
    int idx = 0;    

    // find final size, loop and create substrings
    *returnSize = (c2 - c1 + 1) * (r2 - r1 + 1);
    char **res = malloc(*returnSize * sizeof(char *));

    for(int c = c1; c <= c2; c++) {
        for(int r = r1; r <= r2; r++) {
            char *cell = malloc(3);
            cell[0] = c;
            cell[1] = digits[r];
            cell[2] = '\0';

            res[idx++] = cell;
        }
    }
    return res;
}