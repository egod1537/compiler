static int counter = 0;
extern int external_value;

int main(void)
{
    register int index;
    volatile int flag;
    const unsigned long limit = 3;
    index = 0;
    flag = 1;
    counter = index + flag + limit;
    return counter;
}
