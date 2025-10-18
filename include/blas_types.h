#ifndef _BLAS_TYPES_H_
#define _BLAS_TYPES_H_

typedef long long ll;

enum VALID_FUNCTIONS {
    AXPY,
    COPY,
    DOT,
    NRM2,
    SCAL,
    SWAP,
    INVALID_FUNC,
};

enum VALID_FUNCTIONS convert(char *str);

typedef struct {
    ll n;
    enum VALID_FUNCTIONS f;
} benchmark_info;

typedef void (*BENCHMARK_FUNC)(benchmark_info *info);

#endif
