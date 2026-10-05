int main(void)
{
    int i;
    int sum;
    i = 0;
    sum = 0;

    while (i < 3) {
        sum = sum + i;
        i++;
    }

    do {
        sum = sum - 1;
    } while (sum > 10);

    for (i = 0; i < 5; i++) {
        if (i == 2)
            continue;
        else
            sum = sum + i;
    }

    switch (sum) {
    case 0:
        sum = 1;
        break;
    default:
        break;
    }

    return sum;
}
