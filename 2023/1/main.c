#include <ctype.h>   // isdigit
#include <stdio.h>   // fopen, fgets, fclose, printf
#include <stdlib.h>  // atoi
#include <string.h>  // strlen

/*
Document consists of lines of text.
Each line contained a specific calibration value.
On each line, the calibration value can be found by combining the first digit
and the last digit (in that order) to form a single two-digit number.

Example:
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

In the example, the value are 12, 38, 15, and 77. Adding these together produces
142.

Considering your entire calibration document. What is the sum of all of the
calibration values?
*/

int sumOfCalibrationValues(FILE *input) {
  char line[100];
  int sum = 0;

  while (fgets(line, sizeof(line), input)) {
    char *first_digit = line;
    while (*first_digit && !isdigit(*first_digit)) first_digit++;

    char *last_digit = line + strlen(line) - 2;  // -1 for \n, -2 for \0
    while (*last_digit && !isdigit(*last_digit)) last_digit--;

    char two_digit_number[3] = {*first_digit, *last_digit, '\0'};

    sum += atoi(two_digit_number);
  }

  return sum;
}

// To run:
// gcc 2023/1/main.c -o 2023/1/main && cd 2023/1 && main && cd ../..
int main() {
  FILE *input = fopen("input.txt", "r");  // FILE input

  int sum = sumOfCalibrationValues(input);

  fclose(input);  // close FILE input

  printf("Sum: %d\n", sum);  // 55538

  return 0;
}
