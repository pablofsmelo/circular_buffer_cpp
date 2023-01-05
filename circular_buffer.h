/*
*
* @brief Simple circular buffer is written in C++ and easily portable to many different systems
* @Author: Pablo Melo
* @Version: 0.0.1
* @TODO: Implement Peek, BufferStatus and ClearBuffer
*
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CIRCULAR_BUFFER
#define CIRCULAR BUFFER

/* Includes ------------------------------------------------------------------*/
#include <iostream>

/* Defines -------------------------------------------------------------------*/
#define BUFFER_SIZE 6
 
 
 /* Structures --------------------------------------------------------*/
 struct buff_status{
        int size_total;
        int capacity_available;
        int amount_used;
};

 /* Classes ----------------------------------------------------------------*/
class CircularBuffer {
    
    private:
        int buffer[BUFFER_SIZE];     /* Data buffer memory */
        void *end_of_buffer;         /* End of buffer */
        unsigned int amount_items;   /* Number of items in queue */
        int end_index;               /* Index of Head */
        unsigned int start_index;    /* Index of Tail */

        bool IsEmpty(void);         /* Check if buffer is empty*/
        bool IsFull(void);          /* Check if buffer is full */

    public:
        CircularBuffer(void);                              /* Default constructor, will initialize head and tail indexes for control*/
        bool Enqueue(int* data, int size_buf);             /* Inserts data into internal buffer */
        bool Dequeue(int* buff, unsigned int num_elements); /* Remove num_elements from the buffer */
        void BufferStatus(buff_status * data);              /* Return the buffer status */
        void ClearAllBuffer(void);                          /* Remove all elements from the buffer */
        int Peek(void);                                     /* Get the first element in the buffer */

};

#endif