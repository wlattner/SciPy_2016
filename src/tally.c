#include <stddef.h>

double tally(double *s, size_t n) {
    double total = 0;
    for (size_t i = 0; i < n; i++) {
        total += s[i];
    }
    return total;
}
