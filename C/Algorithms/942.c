/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *diStringMatch(char *S, int *returnSize) {
  int size = strlen(S) + 1;
  int *arr = malloc((size + 1) * sizeof *arr);
  if (!arr)
    return NULL;
  int i = 0, j = size - 1, k = 0;
  while (*S) {
    if (*S++ == 'I') {
      arr[k++] = i;
      i++;
    } else {
      arr[k++] = j;
      j--;
    }
  }
  arr[k] = j;
  *returnSize = size;
  return arr;
}
