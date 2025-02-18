# custom print library

A lightweight, cross-platform C library for printing various data types and modifying the color of the standard output stream via a single, unified interface. This library is primarily designed for debugging purposes.

---

## overview of functionalities

- **`print(...)`**  
  Supports up to 10 arguments. For floating-point types (`float` and `double`), the output is limited to an accuracy of 0.000001. `print(...)` supports following argument types:
  -  signed char
  -  short
  -  int
  -  long
  -  long long
  -  unsigned char
  -  unsigned short
  -  unsigned int
  -  unsigned long
  -  unsigned long long
  -  float
  -  double
  -  _Bool
  -  char
  -  char*
  <br>
  this excludes void*, arrays and constants

- **`change_print_color(Color color)`**  
  Changes the text color of the standard output stream. Can be called via `change_color(color)` macro. It accepts the following arguments:
  - `RED`
  - `GREEN`
  - `BLUE`
  - `YELLOW`
  - `WHITE`
  - `RESET`

---

## demonstration (example.c)

```c
#include "src/print.h"

int main() {
    char* test = "hello world!";
    double result = 4.321;
    print_color(YELLOW);
    print("INFO: ");
    print_color(WHITE);
    print("function succeeded, result: ", result, "\n");
    print_color(RESET);
    print(test);
    return 0;
}
```

---

## file structure

- **print.h**  
  Contains the primary API declarations, type definitions, and macros used for printing, changing text color, and handling multiple arguments.

- **LinPrint.c**  
  Provides the implementation for Linux systems using system calls to write directly to `STDOUT_FILENO`.

- **WinPrint.c**  
  Provides the implementation for Windows systems using the Win32 API.

- **PlatformCheck.h**  
  Detects the target platform (Linux or Windows) and conditionally includes the appropriate implementation file.

---

## compilation and usage

This library is free to use and integrate into any project. To experiment with the provided `example.c` file, simply download the source code and compile it using one of the provided build scripts:

- **Linux**: `./build.sh`
- **Windows**: `build.bat`

The provided build files are configured for `gcc`, but the library is compatible with any compiler that supports C11 features.
