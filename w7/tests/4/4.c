int f(void *p) {
    return 1;
}

int main() {
    int a;
    return f(&a);
}
