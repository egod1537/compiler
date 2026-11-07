struct Point {
    int x;
    int y;
} origin;
int main() {
    struct Point *p;
    p = &origin;
    return p->x;
}
