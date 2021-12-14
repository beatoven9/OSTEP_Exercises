#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELEN 255

void wgrepFile(char *searchTerm, FILE *inputStream);
FILE *openFile(char *fileName);

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    } else if (argc == 2){
        wgrepFile(argv[1], stdin);
    } else if (argc > 2){
        for (int i=2; i<argc; i++){
            FILE *inputStream = openFile(argv[i]);
            wgrepFile(argv[1], inputStream);
        }
    }
}

FILE *openFile(char *fileName){
    FILE *inputStream;
    if ((inputStream = fopen(fileName, "r")) == NULL){
        fprintf(stderr, "wgrep: cannot open file\n");
        exit(1);
    }
    return inputStream;
}

void wgrepFile(char *searchTerm, FILE *inputStream){
    char *lineBuffer;
    size_t bufsize = LINELEN;

    lineBuffer = (char *) malloc(bufsize * sizeof(char));
    int lineBufferLen;
    int searchTermLen = strlen(searchTerm);

    while((lineBufferLen = getline(&lineBuffer, &bufsize, inputStream)) != EOF){
        int x = 0;
        int match = 0;
        for (int i = 0; i <= lineBufferLen - searchTermLen ; i++){
            if (searchTerm[x] == lineBuffer[i]){
                match = 1;
            }
            while (match && (searchTerm[x] != '\0')){
                if (searchTerm[x] == lineBuffer[i+x]){
                    x++;
                } else {
                    match = 0;
                    x=0;
                }
            }
            if (match){
                printf("%s", lineBuffer);
                break;
            }
        }
    }
} 

