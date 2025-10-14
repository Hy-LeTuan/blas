project('blas', 'c', version: '1.0')

# setup global variables flags

link_args = ['-lm', '-pg']
incdir = include_directories('include')

# setup sources

core_sources = [
  './src/ops/vector_ops.c',
  './src/utils/allocate_utils.c',
  './src/bench/vector_ops_bench.c'
]

executable_sources = core_sources + [
  './src/main.c'
]

test_sources = core_sources + [
  './test/vector_ops_test.c'
]

# adding executables for tests

test_executable = executable(
  'vector_ops_test',
  sources: test_sources,
  include_directories: incdir,
  link_args: link_args
)
test('Level 1 vector operations test', test_executable)

# main executable

executable(
  'blas',
  sources: executable_sources,
  c_args : ['-pg'],
  include_directories: incdir,
  link_args: link_args
)


