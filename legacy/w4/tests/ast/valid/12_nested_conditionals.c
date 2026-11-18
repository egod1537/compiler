int choose(int first, int second, int enabled)
{
    if (enabled)
        if (first > second)
            return first;
        else
            return second;
    else
        return 0;
}

int main()
{
    return choose(4, 7, 1);
}
