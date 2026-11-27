int main() {
  int i;
  for (i = 0; i < 3; i++) {
    if (i)
      continue;
    else
      break;
  }
  return i;
}
