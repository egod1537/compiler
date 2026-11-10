struct Point {
    int x;
    int y;
} origin;

enum Color {
    RED,
    GREEN = 2,
    BLUE
} current_color;

int main(void)
{
    struct Point point;
    enum Color color;
    point.x = 1;
    point.y = 2;
    color = GREEN;
    return point.x + point.y + color;
}
