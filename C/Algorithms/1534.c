int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
    int ai, aj, ak, abs, abstemp, count = 0;
    // Build combinations:
    for(unsigned i = 0; i < arrSize; i++){
        ai = arr[i];
        for(unsigned j = i + 1; j < arrSize; j++){
            aj = arr[j];
            // absolute val.
            abstemp = ai - aj;
            abs = abstemp < 0 ? -abstemp : abstemp;
            // Bail early if we don't satisfy first condition.
            if (a >= abs){
                for(unsigned k = j+1; k < arrSize; k++){
                    ak = arr[k];
                    // absolute val.
                    abstemp = aj - ak;
                    abs = abstemp < 0 ? -abstemp : abstemp;
                    // Check the rest of the conditions.
                    if (b >= abs){
                        abstemp = ai - ak;
                        abs = abstemp < 0 ? -abstemp : abstemp;
                        if (c >= abs)
                            count++;
                    }        
                }
            }
        }
    }
    return count;
}
