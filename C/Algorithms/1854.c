#define COUNTS_SIZE 101

int maximumPopulation(int **logs, int logsSize, int *logsColSize) {
  // hold the counts for each year. Year can be found by
  int counts[COUNTS_SIZE] = {0};

  // Fill in counts for each range.
  int max = 0;
  for (int i = 0; i < logsSize; i++) {
    int start = logs[i][0], end = logs[i][1];
    // subtract 1950 to go from [1950, 2050] range
    // to [0, 100] range. (both are inclusive).
    for (int j = start - 1950; j < end - 1950; j++) {
      counts[j]++;
      if (max < counts[j])
        max = counts[j];
    }
  }
  // find min index in counts with value == max.
  int index = 0;
  for (int i = 0; i < COUNTS_SIZE; i++) {
    if (counts[i] == max) {
      index = i;
      break;
    }
  }
  // from index => years.
  return index + 1950;
}