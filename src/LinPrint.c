#include "PlatformCheck.h"
#if linux

int print_i64(long long buffer) {
    _Bool negative = (buffer < 0);
    if (negative)
        buffer = -buffer;
    char* newbuffer = (char*)malloc(25 * sizeof(char));
    long long i = 0;
    do {
        newbuffer[i++] = '0' + (buffer % 10);
        buffer /= 10;
    } while (buffer > 0);
    if (negative)
        newbuffer[i++] = '-';
    newbuffer[i] = '\0';
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = newbuffer[j];
        newbuffer[j] = newbuffer[k];
        newbuffer[k] = temp;
    }
    int output_length = print_string(newbuffer);
    free(newbuffer);
    return output_length;
}

int print_u64(unsigned long long buffer) {
    char* newbuffer = (char*)malloc(25 * sizeof(char));
    long long i = 0;
    do {
        newbuffer[i++] = '0' + (buffer % 10);
        buffer /= 10;
    } while (buffer > 0);
    newbuffer[i] = '\0';
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = newbuffer[j];
        newbuffer[j] = newbuffer[k];
        newbuffer[k] = temp;
    }
    int output_length = print_string(newbuffer);
    free(newbuffer);
    return output_length;
}

int print_f64(double buffer) {
    _Bool negative = (buffer < 0);
    if (negative)
        buffer = -buffer;
    long long int_part = (long long)buffer;
    double fraction = buffer - (double)int_part;
    int int_length = 0;
    long long temp = (int_part == 0) ? 1 : int_part;
    while (temp) {
        temp /= 10;
        int_length++;
    }
    int frac = (int)(fraction * 1000000);
    while (frac != 0 && frac % 10 == 0)
        frac /= 10;
    char* newbuffer = (char*)malloc(25 * sizeof(char));
    long long i = 0;
    do {
        newbuffer[i++] = '0' + (frac % 10);
        frac /= 10;
    } while (frac > 0);
    newbuffer[i++] = '.';
    do {
        newbuffer[i++] = '0' + (int_part % 10);
        int_part /= 10;
    } while (int_part > 0);
    if (negative)
        newbuffer[i++] = '-';
    newbuffer[i] = '\0';
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = newbuffer[j];
        newbuffer[j] = newbuffer[k];
        newbuffer[k] = temp;
    }
    int output_length = print_string(newbuffer);
    free(newbuffer);
    return output_length;
}

int print_bool(_Bool buffer) {
    char ch = (buffer) ? '1' : '0';
    return print_char(ch);
}

int print_char(char buffer) {
    syscall(SYS_write, STDOUT_FILENO, &buffer, 1);
    return 1;
}

int print_string(char* buffer) {
    if (!buffer) return 0;
    const char* buffer_copy = buffer;
    unsigned int length = 0;
    while (*buffer++) length++;
    syscall(SYS_write, STDOUT_FILENO, buffer_copy, length);
}

void change_print_color(Color color) {
    switch (color) {
        case RED: syscall(SYS_write, STDOUT_FILENO, "\033[31m", 5); break;
        case GREEN: syscall(SYS_write, STDOUT_FILENO, "\033[32m", 5); break;
        case BLUE: syscall(SYS_write, STDOUT_FILENO, "\033[34m", 5); break;
        case YELLOW: syscall(SYS_write, STDOUT_FILENO, "\033[33m", 5); break;
        case WHITE: syscall(SYS_write, STDOUT_FILENO, "\033[37m", 5); break;
        case RESET: syscall(SYS_write, STDOUT_FILENO, "\033[0m", 4); break;
        default: return;
    }
}

#endif