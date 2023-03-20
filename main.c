/*
Gita Gliaudytė
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10000
#define MAX_LINE_LENGTH 255


void readFileAndPrint(char *argv[], char error[]);
void findLongestWord(char *lineData, char word[]);

int main(int argc, char *argv[])
{
    char error[MAX_LINE_LENGTH] = {"Error occurred while trying open input or output file.\n"};

    readFileAndPrint(argv, error);

   return 0;
}
void readFileAndPrint(char *argv[], char error[])
{
    char *inputFile = argv[1];
    char *lineData;
    FILE *input;
    lineData = calloc(MAX, sizeof(char));

    if(input = fopen(inputFile, "r")){

        char *outputFile = argv[2];
        FILE *output;

        if(output = fopen(outputFile, "w")){

        while(fgets(lineData, MAX, input)){

            char *longestWord = malloc(MAX_LINE_LENGTH * sizeof(char));

            findLongestWord(lineData, longestWord);

            fprintf(output, "%s", longestWord);
            fputc('\n', output);
            free(longestWord);
        }
        fclose(output);
        } else{
            puts(error);
        }
    }else{
        puts(error);
    }

    free(lineData);
    fclose(input);
}
void findLongestWord(char *lineData, char word[])
{
    int length = strlen(lineData);
    int longestWordLength = 0;
    int seek = 0;
    int index = 0;

    if (length > MAX_LINE_LENGTH){
        length = MAX_LINE_LENGTH;
        lineData[length - 1] = '\0';
    }
    while(length > seek){
        if(!isspace(lineData[seek])){
            ++seek;
            ++index;
        } else{
            ++seek;
            if(index > longestWordLength){
                longestWordLength = index;
                index = 0;
            }
            index = 0;
        }
    }
    seek = 0;
    index = 0;

    while(length > seek){
        if(!isspace(lineData[seek])){
            word[index] = lineData[seek];
            ++seek;
            ++index;
        } else{
            ++seek;
            if(index == longestWordLength){
                break;
            }
            index = 0;
        }
    }
}
