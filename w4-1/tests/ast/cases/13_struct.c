struct Point {
    int x;
    int y;
} origin;

int main(void)
{
    struct Point point;
    point.x = 1;
    point.y = 2;
    return point.x + point.y;
}
