#include "get_next_line.h"

int main()
{
    char *c = NULL;
    int fd = open("test.txt",O_RDONLY);
    c = get_next_line(fd);
    printf("%s",c);
    free(c);
    printf("%d\n",fd);
    close(fd);
    fd = open("test.txt",O_RDONLY);
    c = get_next_line(fd);
    printf("%s",c);
    free(c);
    printf("%d\n",fd);
}