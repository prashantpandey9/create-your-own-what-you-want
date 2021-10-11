/* Print a sequence of numbers */

#include <stdlib.h>
#include <stdio.h>

void seq_from_last(int last) {
    int i;
    for (i = 1; i <= last; i++) {
        printf("%d\n", i);
    }
}

void seq_from_first_and_last(int first, int last) {
    int i;
    for (i = first; i <= last; i++) {
        printf("%d\n", i);
    }
}

int main() {
    seq_from_last(5);               /* 1 2 3 4 5 */
    seq_from_first_and_last(7, 9);  /* 7 8 9 */

    return EXIT_SUCCESS;
}
