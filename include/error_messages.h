#ifndef _ERROR_MESSAGES_H
#define _ERROR_MESSAGES_H

/*
 * Messages about parsing CLI arguments passed in from the user
 */
#define ERROR_NO_FUNCTION_FOUND                                                        \
    "Error: No function name provided. A function name must be passed in either "      \
    "through the -f flag or as a standalone argument.\n"

#define ERROR_INVALID_FUNCTION                                                         \
    "Error: Invalid function name provided, check for valid function names by "        \
    "running blas --usage."

#define ERROR_INTERNAL_INVALID_FUNCTION                                                \
    "Error: Invalid function name provided internally. This could be caused by "       \
    "passing a function name containing invalid keywords."

#endif
