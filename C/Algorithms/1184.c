int distanceBetweenBusStops(int *distance, int distanceSize, int start,
                            int destination) {
  // sum to start, sum to dest, sum to end
  int sts = 0, std = 0, ste = 0, j = 1;
  while (distanceSize--) {
    int val = *distance++;
    if (j <= start)
      sts += val;
    if (j <= destination)
      std += val;
    ste += val;
    j++;
  }
  int diff;
  if (start > destination)
    diff = sts - std;
  else
    diff = std - sts;

  int diff2 = ste - diff;
  return diff < diff2 ? diff : diff2;
}
