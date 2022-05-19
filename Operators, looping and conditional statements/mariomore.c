#include <cs50.h>
#include <stdio.h>

void print(char c, int height);
int main(void)
{
    int height;
    //ask user for input
    do {
        height = get_int ("Height: ");
    }
    while((height > 8) || (height < 1));

    for (int space = 0; space < height; space++)
    {
        print(' ', height - 1 - space);
        print('#', space + 1);
        print(' ', 2);
        print('#', space + 1);

        printf("\n");

    }
}

void print(char c, int height)
{
    for (int space = 0; space < height; space++)
    {
        printf("%c", c);
    }
}