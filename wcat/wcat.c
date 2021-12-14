#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 512

void wcat(char *fileName);

int main(int argc, char *argv[]){
    for(int i=1; i<argc; i++){
        wcat(argv[i]);
    }
}

void wcat(char *fileName){
    FILE *inputStream;
    char bufferStream[MAXLINE];

    if((inputStream = fopen(fileName, "r")) == NULL ){
        fprintf(stderr, "Error opening File!\n");
        exit(1);
    }

    while (fgets(bufferStream, MAXLINE, inputStream) != NULL){
        printf("%s", bufferStream);
    }
}
