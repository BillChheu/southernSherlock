#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <ctype.h>

char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
char punctuation[6] = {'.', ',', '?', '!', ':', ';'};

int southify(FILE* file, char* word);


int main() {
    char current;
   //        char prev;


        FILE *sherlock;
        FILE *southsherlock;

        char word[30];

        sherlock = fopen("..\\sherlock.txt", "r");
        southsherlock = fopen("..\\southie-sherlock.txt", "w");


        if (sherlock == NULL) {
            puts("This is an empty file!");
            exit(0);
        }

        current = (char) fgetc(sherlock);
         int x = 0;



       while (current != EOF) {

        if (current == '\"' ) {
            fputc(current, southsherlock);
            current = (char) fgetc(sherlock);


            while (current != '\"') {

                if (current != ' ' ) {
                    word[x] = current;
                    x++;

                } else {
                 //   printf("%s\n", word);
                    southify(southsherlock, word);
                    fprintf(southsherlock, "%s ", word);
                    x = 0;
                    memset(word, 0, 30);
                }

                current = (char) fgetc(sherlock);
            }

          if (current == '\"') {
              southify(southsherlock, word);
              fprintf(southsherlock, "%s", word);
              x = 0;
              memset(word, 0, 30);
              fputc(current, southsherlock);
              current = (char) fgetc(sherlock);
          }

        } else {
        fputc(current, southsherlock);
        current = (char) fgetc(sherlock);

        }
    }
       fclose(southsherlock);
       fclose(sherlock);
}


int southify(FILE *file, char* word) {

    char previous;
    char value;

    char punct[1];
    int haspunct = 0;


    if (strcmp(word, "very") == 0) {
        strcpy(word, "wicked");
    } else if (strcmp(word, "Very") == 0) {
        strcpy(word, "Wicked");
    } else if (strcmp(word, "VERY") == 0) {
       strcpy(word, "WICKED");
    }


    for (int a = 0; a < strlen(punctuation); a++) {             // see if the last part of the word is punctuation or is a character
        if (word[strlen(word)-1] == punctuation[a]) {
            punct[0] = punctuation[a];
            haspunct = 1;
            break;
        }
    }

    if (strlen(word) > 3 && haspunct == 0 ) {
        if (word[strlen(word)-1] == 'r' && word[strlen(word)-2] == 'e' && word[strlen(word)-3] == 'e') {

            word[strlen(word)-1] = '\0';
            strcat(word,"yah");
            return 0;

        } else if (word[strlen(word)-1] == 'r' && word[strlen(word)-2] == 'o' && word[strlen(word)-3] == 'o') {

            word[strlen(word)-1] = '\0';
            strcat(word, "wah");
            return 0;
        }

    } else if (strlen(word) > 4 && haspunct == 1) {
        if (word[strlen(word)-2] == 'r' && word[strlen(word)-3] == 'e' && word[strlen(word)-4] == 'e') {

            word[strlen(word)-2] = '\0';
            strcat(word, "yah");
            strcat(word, punct);
            return 0;

        } else if (word[strlen(word)-2] == 'r' && word[strlen(word)-3] == 'o' && word[strlen(word)-4] == 'o') {

            word[strlen(word)-2] = '\0';
            strcat(word, "wah");
            strcat(word, punct);
            return 0;
        }
    }


     if (word[strlen(word)-1] == 'r' && word[strlen(word)-2] == 'i' && haspunct == 0) {
        word[strlen(word) - 1] = '\0';
        strcat(word, "yah");
        return 0;

    } else if (word[strlen(word)-2] == 'r' && word[strlen(word)-3] == 'i' && haspunct == 1) {
        word[strlen(word) - 2] = 'y';
        word[strlen(word)-1] = 'a';
        word[strlen(word)] = 'h';
        strcat(word, punct);
        return 0;
    }







    for (int x = 1; x < strlen(word); x++ ) {
        previous = word[x-1];
        value = word[x];

        for ( int y = 0; y < strlen(vowels); y++) {
            if (previous == vowels[y] && value == 'r') {
                word[x] = 'h';
            } else if (previous == vowels[y] && value == 'R') {
                word[x] = 'H';
            }
        }
    }

    if (strlen(word) > 1 && (word[strlen(word)-1] == 'a')) {
        word[strlen(word)] = 'r';
    } else if (strlen(word) > 1 && word[strlen(word)-1] == 'A') {
        word[strlen(word)] = 'R';
    }

}


