int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration) {
  if (duration == 0)
    return 0;

  int seconds = 0;
  for (int i = 1; i < timeSeriesSize; i++) {
    int a1 = timeSeries[i - 1], a2 = timeSeries[i];
    if (a1 != a2)
      seconds += a2 < (a1 + duration) ? a2 - a1 : duration;
  }
  // Add full duration for last attack.
  return seconds + duration;
}