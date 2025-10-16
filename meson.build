project('blas', 'c', version: '1.0')

# setup global variables flags

link_args = ['-lm', '-pg']
incdir = include_directories('include')

# setup sources

core_sources = [
  # main modules
  './src/bench/bench.c',
  # general
  './src/utils/blas_types.c',
  # operation implementations
  './src/ops/vector_vector_ops.c',
  'src/ops/vector_matrix_ops.c',
  # bench functions
  './src/bench/vector_vector_ops_bench.c',
  # utils
  './src/utils/time_utils.c',
  './src/utils/allocate_utils.c',
]

executable_sources = core_sources + [
  './src/main.c'
]

# creating test executables

vector_vector_operations_test = executable(
  'vector_vector_ops_test',
  sources: core_sources + ['./test/vector_vector_ops_test.c'],
  include_directories: incdir,
  link_args: link_args
)

vector_matrix_operations_test = executable(
  'vector_matrix_ops_test',
  sources: core_sources + ['./test/vector_matrix_ops_test.c'],
  include_directories: incdir,
  link_args: link_args
)

# run test

test('Level 1 vector - vector operations test', vector_vector_operations_test)
test('Level 2 vector - matrix operations test', vector_matrix_operations_test)

# main executable

executable(
  'blas',
  sources: executable_sources,
  c_args : ['-pg'],
  include_directories: incdir,
  link_args: link_args
)


