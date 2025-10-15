#include <blas_types.h>
#include <string.h>

enum VALID_FUNCTIONS convert(char *str) {
    if (strcmp(str, "axpy") == 0 || strcmp(str, "Axpy") == 0 ||
        strcmp(str, "AXPY") == 0) {
        return AXPY;
    } else if (strcmp(str, "copy") == 0 || strcmp(str, "Copy") == 0 ||
               strcmp(str, "COPY") == 0) {
        return COPY;
    } else if (strcmp(str, "dot") == 0 || strcmp(str, "Dot") == 0 ||
               strcmp(str, "DOT") == 0) {
        return DOT;
    } else if (strcmp(str, "nrm2") == 0 || strcmp(str, "Nrm2") == 0 ||
               strcmp(str, "NRM2") == 0) {
        return NRM2;
    } else if (strcmp(str, "scal") == 0 || strcmp(str, "Scal") == 0 ||
               strcmp(str, "SCAL") == 0) {
        return SCAL;
    } else if (strcmp(str, "swap") == 0 || strcmp(str, "Swap") == 0 ||
               strcmp(str, "SWAP") == 0) {
        return SWAP;
    } else if (strcmp(str, "assum") == 0 || strcmp(str, "Assum") == 0 ||
               strcmp(str, "ASSUM") == 0) {
        return ASSUM;
    } else if (strcmp(str, "iamax") == 0 || strcmp(str, "Iamax") == 0 ||
               strcmp(str, "IAMAX") == 0) {
        return IAMAX;
    } else {
        return INVALID_FUNC;
    }
}
