struct S {
  int x;
};

int main(void) {
  struct S s = {1.5};
  return s.x;
}
