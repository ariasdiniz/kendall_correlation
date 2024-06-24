/*
MIT License

Copyright (c) 2024 Aria Diniz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef __KENDALL_CORRELATION
#define __KENDALL_CORRELATION

#include <stdio.h>
#include <stdlib.h>
#include <csvparser.h>

/*
  Calculates the Kendall Correlation between the two first columns
  of the given CSV file.

  @param csv_file_path A (char *) representing the path to the CSV file
  @param col_sep A (char *) representing the character used as separator
  @param csv_header A int representing if the fale have a header line
*/
double kcorr(char *csv_file_path, char *col_sep, unsigned int csv_header);

#endif // __KENDALL_CORRELATION