#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

char* replace(char* raw_data, char* old, char* new);
void sed(int fd, char* old, char* new);

char in_buf[512];
char out_buf[512];



int main(int argc, char *argv[])
{


    if (argc < 3 || argc > 4){
        //i.e. only sed, first word, and second word are given OR
        //sed, first word, second word, filename and something else is given
        printf(1, "wrong number (%d)of cmd line arguments", argc);
        exit();
    }

    int fd;
    if (argc == 3){
        fd = 0;
    }
    else {fd = open(argv[3], 0);}

    char* old = argv[1];
    char* new = argv[2];

    sed(fd, old, new);
    exit();
}


void sed(int fd, char* old, char* new) {
    int n;
    while ((n = read(fd, in_buf, sizeof(in_buf))>0)) {
        strcpy(out_buf, replace(in_buf, old, new));
        write(1, out_buf, strlen(out_buf));
        printf(1, "here");
    }
}

char* replace(char* raw_data, char* old, char* new){
    char* processed_data = "";
    //case 1: both are same size
    if (strlen(old) == strlen(new)) {
        //case 1.1: if both old and new are same strings
        if (strcmp(old, new)==0) {

            return raw_data;
        }       

        //case 1.2: else
        int i;
        for (i = 0;i<strlen(raw_data);i++) {
            if (strcmp(&raw_data[i], &old[0])) {
                // int matching = 1;
                // int j = 1;
                // while (matching) {
                //     if (strcmp(&raw_data[i+j], &old[j])) {
                        
                //     }

                //     if (j==strlen(old)) {
                //         matching = 0;
                //     }
                // }
            }
        }

    }
    

    //case 2: different sizes
    return processed_data;
};
