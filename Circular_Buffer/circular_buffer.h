#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Circular buffer structure for embedded applications.
 */
typedef struct {
    char *buffer;   /**< Pointer to the dynamically allocated buffer memory */
    size_t head;    /**< Index of the head (write position) */
    size_t tail;    /**< Index of the tail (read position) */
    size_t max;     /**< Maximum number of elements in the buffer */
    bool full;      /**< Flag to indicate if the buffer is full */
    
    /**
     * @brief Optional callback function called after each write operation.
     * Pass NULL if not required.
     */
    void (*bufferUpdateCallback)(void);
} CircularBuffer;

/**
 * @brief Initializes a circular buffer with a given size and optional callback.
 * 
 * @param cb Pointer to the CircularBuffer structure (stack-allocated).
 * @param size Size of the buffer to allocate.
 * @param callback Function pointer to be called after each write (can be NULL).
 * @return true if initialization was successful, false otherwise.
 */
bool Init_Circular_Buffer(CircularBuffer *cb, size_t size, void (*callback)(void));

/**
 * @brief Frees the memory allocated for the circular buffer.
 * 
 * @param cb Pointer to the CircularBuffer.
 */
void Free_Circular_Buffer(CircularBuffer *cb);

/**
 * @brief Writes a character to the circular buffer.
 * 
 * @param cb Pointer to the CircularBuffer.
 * @param data Character to write.
 * @return true if the write was successful, false if the buffer was full.
 */
bool Write_To_Buffer(CircularBuffer *cb, char data);

/**
 * @brief Reads a character from the circular buffer.
 * 
 * @param cb Pointer to the CircularBuffer.
 * @param data Pointer to store the character read.
 * @return true if the read was successful, false if the buffer was empty.
 */
bool Read_From_Buffer(CircularBuffer *cb, char *data);

/**
 * @brief Checks if the circular buffer is empty.
 * 
 * @param cb Pointer to the CircularBuffer.
 * @return true if buffer is empty, false otherwise.
 */
bool Is_Buffer_Empty(CircularBuffer *cb);

/**
 * @brief Checks if the circular buffer is full.
 * 
 * @param cb Pointer to the CircularBuffer.
 * @return true if buffer is full, false otherwise.
 */
bool Is_Buffer_Full(CircularBuffer *cb);

/**
 * @brief Prints the current contents of the circular buffer.
 * 
 * @param cb Pointer to the CircularBuffer.
 */
void Print_Buffer(CircularBuffer *cb);

#endif // CIRCULAR_BUFFER_H

