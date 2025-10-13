project('blas', 'c', version: '1.0')

# setup global variables flags

link_args = ['-lm']
incdir = include_directories('include')

# setup sources

core_sources = [
  './src/ops/vector_ops.c'
]

executable_sources = core_sources + [
  './src/main.c'
]

# adding executables for tests

vector_ops_test = executable(
  'vector_ops_test',
  sources: core_sources + ['./test/vector_ops_test.c'],
  include_directories: incdir,
  link_args: link_args
)
test('Level 1 vector operations test', vector_ops_test)

# main executable

executable(
  'blas',
  sources: executable_sources,
  c_args : ['-O3'],
  include_directories: incdir,
  link_args: link_args
)


