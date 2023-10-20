#include <stdbool.h>
#include <ctype.h>

bool is_empty_line(char *line) {
    while (*line) {
        if (!isspace((unsigned char)*line))
            return false;
        line++;
    }
    return true;
}
