#include <stdio.h>
#include <stdlib.h>

int *get_multipliers(int size){
    unsigned int odd_len = 0;
    int *arr;
    unsigned *odds, *occurs;
    int mid; 
    
    // find number of odds.
    if (size % 2)
        odd_len = (size / 2) + 1;
    else 
        odd_len = size / 2;
    
    // initialize arrays.
    arr = (int *)malloc(sizeof(int) * size);
    odds = (unsigned *)malloc(sizeof(unsigned) * odd_len);
    occurs = (unsigned *)malloc(sizeof(unsigned) * odd_len);
    
    // populate odds and their occurences.
    for(unsigned i = 1, j = 0; j < odd_len; j++){
        odds[j] = i;
        occurs[j] = (1 + (size - i));
        i += 2;
    }
    
    if (size % 2)
        mid = (size / 2) + 1;
    else
        mid = size / 2;
    
    // first element == # of odds. 
    arr[0] = odd_len;
    for(unsigned idx = 2; idx <= mid; idx++){
        unsigned sum = 0;
        
        for(unsigned j = 0; j < odd_len; j++){
            unsigned odd = odds[j], occur = occurs[j];
            if ((idx < odd) && (occur > idx)){
                sum += idx;
            } else {
                if (odd <= occur)
                    sum += odd;
                else
                    sum += occur;
            }
        }
        arr[idx - 1] = sum;
    }
    for(int i = 0; i < mid; i++){
        printf("%d ", arr[i]);
    }

    if (size % 2){
        for(unsigned i = mid - 1; i >= 1; i--)
           arr[size - i] = arr[i-1];
    }
    else {
        for(unsigned i = mid; i >= 1; i--)
            arr[size - i] = arr[i-1];
    } 
    // free and return.
    free(odds);
    free(occurs);
    return arr;
}


int sumOddLengthSubarrays(int* arr, int arrSize){
    int *mults = get_multipliers(arrSize);
    
    unsigned sum = 0;
    printf("%s", "[");
    for(unsigned i=0; i < arrSize; i++){
        sum += arr[i] * mults[i];
        printf("%d, ", mults[i]); 
    }
    printf("%s\n", "]");
    free(mults);
    return sum;
}

int main(int argc, char **argv){
    int a[5] = {1, 4, 2, 5, 3};
    int res = sumOddLengthSubarrays(a, 5);
    printf("%d\n", res);

   return 0; 
}
