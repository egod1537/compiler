int sum(int values[], int count)
{
    int index;
    int total;
    index = 0;
    total = 0;

    while (index < count) {
        total = total + values[index];
        index++;
    }

    return total;
}

int main(void)
{
    int numbers[4] = { 1, 2, 3, 4 };
    return sum(numbers, 4);
}
