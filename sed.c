#include "user.h"

void sed(int fd, char* old, char* new);

int is_matching(char* old, char* curr);

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
    close(fd);
    exit();
}


void sed(int fd, char* old, char* new) {
    int out_fd = open("input2.txt", O_WRONLY);

    int len = strlen(old);
    char ch[len];
    int n;
    while ((n = read(0, ch, len))>0){
        if (!is_matching(old, ch)){
            write(out_fd, ch, len);
        }
        else {
            write(out_fd, new, strlen(new));
        }
    }

    close(out_fd);
}

int is_matching(char* old, char* curr) {
    int i;
    for (i = 0; i<strlen(old);i++){
        if (old[i] != curr[i]) {
            return 0;
        }
    }
    return 1;
};
