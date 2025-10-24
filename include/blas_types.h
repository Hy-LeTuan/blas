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
    INVALID_FUNC,
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
} benchmark_info;

typedef struct {
    double warmup_time;
    double run_time;
    ll flops;
    ll array_length;
    double *time_records;
} benchmark_result;

typedef void (*Benchmark_Func)(benchmark_info *info);

enum Blas_Functions convert(char *str);
char *convert_blas_func_to_str(enum Blas_Functions f);
enum Blas_Function_Level get_func_level(enum Blas_Functions f);

#endif
