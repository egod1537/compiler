struct Pair {
  int left;
  int right;
};

int main() {
  struct Pair p;
  p.left = 1;
  p.right = 2;
  return p.left + p.right;
}
