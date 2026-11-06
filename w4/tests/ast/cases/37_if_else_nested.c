int main(void) {
    int a, b;
    a = 1;
    b = 0;
    if (a)
        if (b)
            return 1;
        else
            return 2;
    return 3;
}
