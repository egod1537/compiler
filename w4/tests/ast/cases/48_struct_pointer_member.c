struct Point {
    int x;
    int y;
} origin;
int main(void) {
    struct Point *p;
    p = &origin;
    return p->x;
}
