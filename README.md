# Kendell Correlation C Lib

This library adds a function `kcorr` to calculate the Kendall Correlation between the two first columns of the chosen CSV file. These columns are expected to be numbers.

**This project depends on the library [CSV Parser](https://github.com/ariasdiniz/csv_parser).Don't forget to install it or compile it with your project**

```c
#include "kcorr.h"
#include <stdio.h>

int main() {
  printf("Kendall Correlation: %s", kcorr("data.csv", ",", 0));
  return 0;
}
```