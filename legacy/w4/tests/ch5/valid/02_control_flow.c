int sum(int n)
{
    int i;
    int total;

    i = 0;
    total = 0;
    while (i < n) {
        total = total + i;
        i++;
    }

    if (total > 10)
        return total;
    else
        return 0;
}
