int main() {
    int a, b, c;
    a = 8;
    b = 2;
    c = (a + b) << (b - 1);
    if (c >> 2 > a)
        c = c >> 1;
    return c;
}
