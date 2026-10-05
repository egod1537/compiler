int main(void)
{
    int value;
    value = 12;
    value = value & 7;
    value = value | 16;
    value = value ^ 3;
    value = value << 1;
    value = value >> 2;
    value = ~value;
    return value;
}
