# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main(void) {
    int fd1;
    char buf[256];
    int chars_read;

/* WRITES INTO A FILE "SAMPLE.TXT"
    int fd;
    fd = open("sample.txt", O_RDONLY);
    printf("fd of file: %d\n", fd);
    write(3, "living forever \n", 15);
    close(fd);
*/

// -- READ AND DISPLAYS ON THE TERMINAL THE TEXT --
    fd1 = open("sample.txt", O_RDONLY);
    while ((chars_read = read(fd1, buf, 5)))
    {
        buf[chars_read] = '\0';
        printf("Buf-> %s\n", buf);
    }

    return 0;

}