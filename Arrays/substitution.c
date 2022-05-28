#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("All characters need to be alphabets\n");  //checks if the key is all alphabets
            return 1;
        }
        for (int j = 0; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j] && i != j)
            {
                printf("No repeating characters allowed in key\n");
                return 1;
            }
        }

    }
        string plaintext = get_string("Plaintext: ");  //  Ask user for plaintext
        printf("ciphertext: ");

        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(argv[1][plaintext[i] - 65])); //make upper case text to uppercase as it is case sensitive.
                //(-65 finds the particular position of the plain text)
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", tolower(argv[1][plaintext[i] - 97]));
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");



}