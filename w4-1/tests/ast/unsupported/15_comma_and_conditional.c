int main(void)
{
    int first;
    int second;
    int result;
    result = (first = 1, second = 2, first + second);
    result = result > 0 ? result : 0;
    return result;
}
