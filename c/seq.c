/* Print a sequence of numbers */

#include <stdlib.h>
#include <stdio.h>

void seq(int last) {
    int i;
    for (i = 1; i <= last; i++) {
        printf("%d\n", i);
    }
}

int main() {
    seq(5);

    return EXIT_SUCCESS;
}
