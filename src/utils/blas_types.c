#include <blas_types.h>
#include <error_messages.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Blas_Functions convert(char *str)
{
    if (strcmp(str, "axpy") == 0 || strcmp(str, "Axpy") == 0 ||
        strcmp(str, "AXPY") == 0) {
        return AXPY;
    }
    else if (strcmp(str, "copy") == 0 || strcmp(str, "Copy") == 0 ||
             strcmp(str, "COPY") == 0) {
        return COPY;
    }
    else if (strcmp(str, "dot") == 0 || strcmp(str, "Dot") == 0 ||
             strcmp(str, "DOT") == 0) {
        return DOT;
    }
    else if (strcmp(str, "nrm2") == 0 || strcmp(str, "Nrm2") == 0 ||
             strcmp(str, "NRM2") == 0) {
        return NRM2;
    }
    else if (strcmp(str, "scal") == 0 || strcmp(str, "Scal") == 0 ||
             strcmp(str, "SCAL") == 0) {
        return SCAL;
    }
    else if (strcmp(str, "swap") == 0 || strcmp(str, "Swap") == 0 ||
             strcmp(str, "SWAP") == 0) {
        return SWAP;
    }
    else if (strcmp(str, "sdgemv_c") == 0 || strcmp(str, "Sdgemv_c") == 0 ||
             strcmp(str, "SDGEMV_C") == 0) {
        return SDGEMV_C;
    }
    else if (strcmp(str, "sdgemv_r") == 0 || strcmp(str, "Sdgemv_r") == 0 ||
             strcmp(str, "SDGEMV_R") == 0) {
        return SDGEMV_R;
    }
    else if (strcmp(str, "sdger_c") == 0 || strcmp(str, "Sdger_c") == 0 ||
             strcmp(str, "SDGER_C") == 0) {
        return SDGER_C;
    }
    else if (strcmp(str, "sdger_r") == 0 || strcmp(str, "Sdger_r") == 0 ||
             strcmp(str, "SDGER_R") == 0) {
        return SDGER_R;
    }
    else {
        fprintf(stderr, ERROR_INVALID_FUNCTION);
        exit(EXIT_FAILURE);
    }
}

char *convert_blas_func_to_str(enum Blas_Functions f)
{
    switch (f) {
    case AXPY:
        return "AXPY";
    case COPY:
        return "COPY";
    case DOT:
        return "DOT";
    case NRM2:
        return "NRM2";
    case SCAL:
        return "SCAL";
    case SWAP:
        return "SWAP";
    case SDGEMV_C:
        return "SDGEMV_C";
        break;
    case SDGEMV_R:
        return "SDGEMV_R";
        break;
    case SDGER_C:
        return "SDGER_C";
        break;
    case SDGER_R:
        return "SDGER_R";
        break;
    default:
        fprintf(stderr, ERROR_INTERNAL_INVALID_FUNCTION);
        exit(EXIT_FAILURE);
    }
}

extern enum Blas_Function_Level get_func_level(enum Blas_Functions f);
