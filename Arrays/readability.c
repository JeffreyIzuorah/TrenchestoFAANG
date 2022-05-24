#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main(void)
{
    int count_letters = 0;
    int count_words = 1;
    int count_sentences = 0;

    string text = get_string("Text: ");

    // int result = count_letters(text);
    // printf("%i\n", result);

    // int wordcount = count_words(text);
    // printf("%i\n", wordcount);

    // int scount = count_sentences(text);
    // printf("%i\n", scount);

    int textlength = strlen(text);

    for (int i=0; i < textlength; i++)
        if (isalpha(text[i])) count_letters++;

    for (int i = 0; i < textlength; i++)
        if (isspace(text[i])) count_words++;

    for (int i = 0; i < textlength; i++)
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') count_sentences++;

    float grade = (0.0588 * count_letters/count_words * 100) - (0.296 * count_sentences/count_words * 100) - 15.8;
    int index = round(grade); //round up index as specified

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
