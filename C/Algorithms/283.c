void moveZeroes(int *nums, int numsSize) {
  int on_zero = 0, run = 0;

  while (1) {
    while (*(nums + on_zero)) {
      on_zero++;
      if (on_zero == numsSize)
        return;
    }

    while (!*(nums + run) || run < on_zero) {
      run++;
      if (run == numsSize)
        return;
    }

    int tmp = *(nums + on_zero);
    *(nums + on_zero) = *(nums + run);
    *(nums + run) = tmp;
  }
}
