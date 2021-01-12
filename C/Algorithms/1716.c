int totalMoney(int n) {
  int weeks = n / 7, days = n % 7, partial = 0, week_sum = 28;
  for (int i = 0; i < weeks; i++) {
    partial += week_sum;
    week_sum += 7;
  }
  for (int i = 1; i <= days; i++)
    partial += weeks + i;
  return partial;
}
