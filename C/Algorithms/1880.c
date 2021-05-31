inline int asInt(char *word) {
  int len = strlen(word) - 1, value = 0;
  while (*word) {
    int cv = (*word++ - 97);
    if (cv) {
      value += pow(10, len) * cv;
    }
    len--;
  }
  return value;
}

bool isSumEqual(char *firstWord, char *secondWord, char *targetWord) {
  return asInt(firstWord) + asInt(secondWord) == asInt(targetWord);
}