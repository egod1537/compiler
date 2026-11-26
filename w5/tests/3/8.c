int global = 10;

int square(int x) {
    return x * x;
}

int main() {
    int a = global;
    int b = square(a);
    return b;
}
