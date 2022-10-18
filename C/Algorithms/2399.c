#include <stdbool.h>

bool checkDistances(char * s, int* distance, int distanceSize){
    int len = strlen(s);
    for (int i = 0; i < len-1; i++) {
        int pos = s[i] - 97;

        // Mark distance if seen.
        int dist = distance[pos] + 1;
        if (dist == -1)
            continue;
        else {
            distance[pos] = -2;
        }
        dist += i;
        if (dist < len && s[dist] == s[i])
            continue;
        else
            return false;
    }
    return true;
}