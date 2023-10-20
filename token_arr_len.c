#include <stddef.h>

size_t token_arr_len(char **tokens) {
    size_t count = 0;
    while (tokens && *tokens) {
        count++;
        tokens++;
    }
    return count;
}
