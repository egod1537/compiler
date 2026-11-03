void swap(int *left, int *right)
{
    int temporary;
    temporary = *left;
    *left = *right;
    *right = temporary;
    return;
}

int main(void)
{
    int first;
    int second;
    first = 10;
    second = 20;
    swap(&first, &second);
    return first;
}
