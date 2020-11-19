int minCostToMoveChips(int *position, int positionSize) {
  int odds = 0;
  for (int i = 0; i < positionSize; i++) {
    if (position[i] % 2)
      odds++;
  }
  return odds < positionSize - odds ? odds : positionSize - odds;
}
