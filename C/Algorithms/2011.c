int finalValueAfterOperations(char ** operations, int operationsSize){
    int result = 0;
    for(int i = 0; i < operationsSize; i++){
        char *op = operations[i];
        if (op[0] == '+' || op[1] == '+')
            result++;
        else
            result--;
    }
    return result;
}