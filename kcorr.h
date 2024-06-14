#ifndef __KENDELL_CORRELATION
#define __KENDELL_CORRELATION

#include <stdio.h>
#include <stdlib.h>
#include <csvparser.h>

double kcorr(char *csv_file_path, char *col_sep, unsigned int csv_header);

#endif // __KENDELL_CORRELATION