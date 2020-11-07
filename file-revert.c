#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define CHAR_SIZE 2048
#define BUFF_SIZE 2
#define PERMS 0666

int main(int argc, char **argv) {

    if (argc < 3) {
        return 1;
        printf ("ERROR: not enough arguments\n");
    }

    int src_file = 0;
    int dest_file = 0;
    int n = -2;
    int nl = '\n';  /* explicit newline when writing in reverse */

    if ((src_file = open (argv[1],O_RDONLY)) == -1) return 1;
    if ((dest_file = creat (argv[2], PERMS)) == -1) return 1;

    printf ("The filesize is: %ld\n", lseek(src_file, (off_t) 0, SEEK_END));

    lseek (src_file, n--, SEEK_END);
#ifdef WBUFCHAR
    int bufchar;
    do {    /* validate both read and write */
        if (read (src_file, &bufchar, BUFF_SIZE - 1) == 0) {
            fprintf (stderr, "error: read failure.\n");
            return 1;
        }
        putchar (bufchar);
        if (write (dest_file, &bufchar, BUFF_SIZE - 1) == 0) {
            fprintf (stderr, "error: write failure.\n");
            return 1;
        }
    } while (lseek (src_file, n--, SEEK_END) > -1);
#else
    char buffer[BUFF_SIZE];
    do {    /* validate both read and write */
        if (read (src_file, buffer, BUFF_SIZE - 1) == 0) {
            fprintf (stderr, "error: read failure.\n");
            return 1;
        }
        buffer[1] = 0;          /* nul-terminate */
        printf ("%s", buffer);
        if (write (dest_file, buffer, BUFF_SIZE - 1) == 0) {
            fprintf (stderr, "error: write failure.\n");
            return 1;
        }
    } while (lseek (src_file, n--, SEEK_END) > -1);
#endif
    /* explicity write the newline you removed earlier */
    if (write (dest_file, &nl, BUFF_SIZE - 1) == 0) {
        fprintf (stderr, "error: write failure.\n");
        return 1;
    }
    putchar ('\n');
    return 0;
} 
