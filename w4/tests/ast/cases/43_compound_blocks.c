int main(void) {
    int x;
    x = 1;
    {
        int y;
        y = 2;
        x = x + y;
    }
    return x;
}
