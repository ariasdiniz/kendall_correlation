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

#include "kcorr.h"

typedef struct Data {
  double *x;
  double *y;
  size_t n;
} Data;

static size_t count_lines(char *csv_file_path, Data *data, char *line) {
  FILE *f = fopen(csv_file_path, "r");
  if (f == NULL) {
    return (size_t)0;
  }
  while ((line = readline(f, line)) != NULL) {
    data->n++;
  }
  fclose(f);
  return data->n;
}

static void fill_data(char *csv_file_path, Data *data, char *line, char **buffer, unsigned int csv_header) {
  FILE *f = fopen(csv_file_path, "r");
  data->x = malloc((sizeof(double) * data->n));
  data->y = malloc((sizeof(double) * data->n));
  double sx = 0, sy = 0, bx = 0, by = 0;
  size_t i = 0;
  if (csv_header) line = readline(f, line);

  while ((line = readline(f, line)) != NULL) {
    buffer = parseline(line, ",", buffer);
    data->x[i] = atof(buffer[0]);
    data->y[i] = atof(buffer[1]);
    i++;
  }
  fclose(f);
  freeparsedline(buffer);
  free(line);
}

static double tau(Data *data) {
  double concordant = 0, discordant = 0;
  double dx, dy;
  for (size_t i = 0; i < data->n - 1; i++) {
    for (size_t j = i + 1; j < data->n; j++) {
      dx = data->x[i] - data->x[j];
      dy = data->y[i] - data->y[j];
      if (dx * dy > 0) {
        concordant++;
      } else if (dx * dy < 0) {
        discordant++;
      }
    }
  }
  size_t total_pairs = data->n * (data->n - 1) / 2;
  return (concordant - discordant) / (double)total_pairs;
}

double kcorr(char *csv_file_path, char *col_sep, unsigned int csv_header) {
  char *line = NULL;
  char **buffer = NULL;
  Data *data = malloc(sizeof(Data));
  data->n = 0;
  if (csv_header) data->n = -1;

  if (!count_lines(csv_file_path, data, line)) {
    fprintf(stderr, "File not found or empty: %s\n", csv_file_path);
    return 0.0;
  }
  fill_data(csv_file_path, data, line, buffer, csv_header);
  double t = tau(data);

  free(data->x);
  free(data->y);
  free(data);
  return t;
}