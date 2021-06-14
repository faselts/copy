#include<stdio.h>
#include <fcntl.h>
#include<string.h>
int main(int argc, char *argv[])
{
    int fdo = open("old.txt", O_RDWR | O_CREAT );
    int fdw = open("new.txt", O_RDWR | O_CREAT );
    char *r = (char *) calloc(10, sizeof(char));
    char *w = (char *) calloc(10, sizeof(char));
    int sz=1;
    while(sz!=0){
        sz=read(fdo, r, 10);
        r[sz]='\0';
        write(fdw, r, strlen(r));
    }
    close(fdo);
    close(fdw);
}
