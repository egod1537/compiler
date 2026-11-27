union Number {
  int i;
  float f;
};

int main() {
  union Number n;
  n.i = 4;
  return n.i;
}
