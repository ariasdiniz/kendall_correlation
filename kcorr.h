#ifndef __KENDALL_CORRELATION
#define __KENDALL_CORRELATION

#include <stdio.h>
#include <stdlib.h>
#include <csvparser.h>

/*
  Calculates the Kendall Correlation between the two first columns
  of the given CSV file.
*/
double kcorr(char *csv_file_path, char *col_sep, unsigned int csv_header);

#endif // __KENDALL_CORRELATION