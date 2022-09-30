typedef struct _person {
    char *name;
    int height;
} Person;

// Comparator for people
int cmp_people(const void *a, const void *b)
{
    const Person *x = (Person *)a;
    const Person *y = (Person *)b;
    
    return (x->height < y->height) - (x->height > y->height);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** sortPeople(char ** names, int namesSize, int* heights, int heightsSize, int* returnSize){
    Person *people = malloc(heightsSize * sizeof(*people));
    for (int i = 0; i < heightsSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }
    qsort(people, heightsSize, sizeof(*people), cmp_people);
    // re-use space from names.
    for (int i = 0; i < heightsSize; i++) {
        names[i] = people[i].name;
    }
    free(people);
    *returnSize = heightsSize;  

    return names;
}