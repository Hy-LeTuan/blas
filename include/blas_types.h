#ifndef _BLAS_TYPES_H_
#define _BLAS_TYPES_H_

typedef long long ll;

#define AVERAGE_UNIT "(s/iter)"
#define TIME_UNIT "(s)"

enum Blas_Functions {
    AXPY,
    COPY,
    DOT,
    NRM2,
    SCAL,
    SWAP,
    SDGEMV_C,
    SDGEMV_R,
    SDGER_C,
    SDGER_R,
};

enum Blas_Function_Level {
    VEC_VEC,
    VEC_MAT,
};

typedef struct {
    ll n;
    ll m;
    ll iteration;
    ll cache_warmup;
    enum Blas_Functions f;
} BenchmarkInfo;

typedef struct {
    double warmup_time;
    double run_time;
    ll flops;
    ll array_length;
    double *time_records;
} BenchmarkResult;

typedef void (*Benchmark_Func)(BenchmarkInfo *info);
enum Blas_Functions convert(char *str);
char *convert_blas_func_to_str(enum Blas_Functions f);

inline enum Blas_Function_Level get_func_level(enum Blas_Functions f)
{
    switch (f) {
    case AXPY:
    case COPY:
    case DOT:
    case NRM2:
    case SCAL:
    case SWAP:
        return VEC_VEC;
    case SDGEMV_C:
    case SDGEMV_R:
    case SDGER_C:
    case SDGER_R:
        return VEC_MAT;
    default:
        return VEC_VEC;
    }
}

#endif
