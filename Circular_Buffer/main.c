#include <stdio.h>
#include "circular_buffer.h"

void onBufferUpdate() {
    printf("[Callback] Buffer was updated.\n");
}

int main() {
    CircularBuffer cb;

    if (!Init_Circular_Buffer(&cb, 5, onBufferUpdate)) {
        printf("Failed to initialize buffer.\n");
        return -1;
    }

    Write_To_Buffer(&cb, 'A');
    Write_To_Buffer(&cb, 'B');
    Write_To_Buffer(&cb, 'C');

    Print_Buffer(&cb);

    char ch;
    if (Read_From_Buffer(&cb, &ch)) {
        printf("Read: %c\n", ch);
    }

    Write_To_Buffer(&cb, 'D');
    Write_To_Buffer(&cb, 'E');
    Write_To_Buffer(&cb, 'F'); // Should not be written if full

    Print_Buffer(&cb);

    printf("Is Full: %s\n", Is_Buffer_Full(&cb) ? "Yes" : "No");
    printf("Is Empty: %s\n", Is_Buffer_Empty(&cb) ? "Yes" : "No");

    Free_Circular_Buffer(&cb);
    return 0;
}

