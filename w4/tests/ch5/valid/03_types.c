struct Pair {
    int left;
    int right;
};

enum Color {
    RED,
    GREEN,
    BLUE
};

int select(enum Color color, struct Pair *pair)
{
    return pair->left;
}
