#include <stdio.h>
#include <time.h>

void time_function() {
    clock_t start = clock();
    clock_t stop = clock();

    printf("Time taken is: %lf seconds\n",
           ((double)stop - (double)start) / (double)CLOCKS_PER_SEC);
}

int main(void) {
    printf("Hello, word\n");

    return 0;
}
