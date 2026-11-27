int *identity(int *p) {
  return p;
}

int main() {
  int x = 9;
  return *identity(&x);
}
