#ifndef _BLAS_TYPES_H_
#define _BLAS_TYPES_H_

typedef long long ll;

enum BLAS_FUNCTIONS {
    AXPY,
    COPY,
    DOT,
    NRM2,
    SCAL,
    SWAP,
    INVALID_FUNC,
};

typedef struct {
    ll n;
    ll iteration;
    ll cache_warmup;
    enum BLAS_FUNCTIONS f;
} benchmark_info;

typedef struct {
    double time;
    ll flops;
} benchmark_result;

typedef void (*BENCHMARK_FUNC)(benchmark_info *info);

enum BLAS_FUNCTIONS convert(char *str);
char *display_enum(enum BLAS_FUNCTIONS f);

#endif
