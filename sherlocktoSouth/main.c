#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <dmalloc.h>
#include <string.h>

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {

    FILE *sherlock;

    char word[30];

    sherlock = fopen("C:\\Users\\tuh04091\\CLionProjects\\sherlocktoSouth\\sherlock.txt", "r+");

    if (sherlock == NULL) {
        puts("This is an empty file!");
        exit(0);
    }

    fscanf(sherlock, "%s", word);

    while (!(feof(sherlock))) {
        fscanf(sherlock, "%s", word);

        if (word[0] == '\"') {
            printf("%s", word);
        }

    }


    // fscanf(sherlock, "%s", word);
   // printf("%s", word);


}


int southify(FILE *file, char* word) {

    char previous;
    char value;

    for (int x = 1; x < strlen(word); x++ ) {
        previous = word[x-1];
        value = word[x];

        for ( int y = 0; y < strlen(vowels); y++) {
            if (previous == vowels[y] && value == 'r') {
                
            }
        }

    }
}