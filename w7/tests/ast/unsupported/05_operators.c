int main(void)
{
    int a;
    int b;
    int *pointer;
    a = 8;
    pointer = &a;
    b = *pointer;
    b = (b << 1) | 1;
    b = b > 10 && a != 0 ? b : a;
    b = b + sizeof(int);
    goto done;
    b = 0;
done:
    return b;
}
