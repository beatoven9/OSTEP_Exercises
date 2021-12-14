#include <stdio.h>
#include <stdlib.h>

#define LINELEN 255

void wgrep(char *searchTerm, char *fileName);

int main(int argc, char *argv[]){
    for (int i=2; i<argc; i++){
        wgrep(argv[1], argv[i]);
    }
}

void wgrep(char *searchTerm, char *fileName){
    FILE *inputStream;

    char *lineBuffer;
    size_t bufsize = LINELEN;

    if ((inputStream = fopen(fileName, "r")) == NULL){
        fprintf(stderr, "Error opening file: %s\n", fileName);
    }

    lineBuffer = (char *) malloc(bufsize * sizeof(char));

    while(getline(&lineBuffer, &bufsize, inputStream) != EOF){
        //Here is where we will check for a substring matching the search term.
        //Prolly we'll do this with nested loops doing comparisons.
        printf("%s", lineBuffer);
    }
} 

