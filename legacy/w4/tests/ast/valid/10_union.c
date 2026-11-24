union Number {
    int integer_value;
    float float_value;
} number;

int main()
{
    union Number local;
    local.integer_value = 42;
    number.float_value = 1.5;
    return local.integer_value;
}
