#pragma once

#include <stdlib.h>
#include <windows.h>
#define WIN32_LEAN_AND_MEAN

typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    WHITE,
    RESET
} Color;

#define print_one(x) _Generic((x), \
    signed char: print_i64, \
    short: print_i64, \
    int: print_i64, \
    long: print_i64,   \
    long long: print_i64, \
    unsigned char: print_i64, \
    unsigned short: print_u64, \
    unsigned int: print_u64, \
    unsigned long: print_u64, \
    unsigned long long: print_u64, \
    float: print_f64, \
    double: print_f64, \
    _Bool: print_bool, \
    char: print_char, \
    char*: print_string \
)(x)

#define FE_1(WHAT, X) (WHAT(X))
#define FE_2(WHAT, X, ...) ((WHAT(X)) + FE_1(WHAT, __VA_ARGS__))
#define FE_3(WHAT, X, ...) ((WHAT(X)) + FE_2(WHAT, __VA_ARGS__))
#define FE_4(WHAT, X, ...) ((WHAT(X)) + FE_3(WHAT, __VA_ARGS__))
#define FE_5(WHAT, X, ...) ((WHAT(X)) + FE_4(WHAT, __VA_ARGS__))
#define FE_6(WHAT, X, ...) ((WHAT(X)) + FE_5(WHAT, __VA_ARGS__))
#define FE_7(WHAT, X, ...) ((WHAT(X)) + FE_6(WHAT, __VA_ARGS__))
#define FE_8(WHAT, X, ...) ((WHAT(X)) + FE_7(WHAT, __VA_ARGS__))
#define FE_9(WHAT, X, ...) ((WHAT(X)) + FE_8(WHAT, __VA_ARGS__))
#define FE_10(WHAT, X, ...) ((WHAT(X)) + FE_9(WHAT, __VA_ARGS__))

#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,NAME,...) NAME

#define FOR_EACH(action, ...) \
    GET_MACRO(__VA_ARGS__, FE_10, FE_9, FE_8, FE_7, FE_6, FE_5, FE_4, FE_3, FE_2, FE_1)(action, __VA_ARGS__)

#define print(...) FOR_EACH(print_one, __VA_ARGS__)

int print_i64(long long buffer);
int print_u64(unsigned long long buffer);
int print_f64(double buffer);
int print_bool(_Bool buffer);
int print_char(char buffer);
int print_string(char* buffer);

void change_print_color(Color color);
#define print_color(color) change_print_color(color)
