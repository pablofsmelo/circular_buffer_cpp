#include "circular_buffer.h"

using namespace std;

/**
 * @brief   Constructor to initialize the attributes of class CircularBuffer
 * @param void  
 * @return void
 **/
CircularBuffer::CircularBuffer()
{
     end_index = start_index = amount_items = 0;
}


/**
 * @brief The function adds a data buffer to a ring buffer
 * @param int *data - The buffer allocated for the ring buffer  
 * @param int sizebuf - The size of the allocated ring buffer
 * @return bool - (0) if error or full ; (1)if data was inserted
 **/
bool CircularBuffer::Enqueue(int *data, int size_buf)
{       
    if (data == NULL || buffer == NULL) return 0;

    if (IsFull()) return 0;

     if (amount_items + size_buf <= BUFFER_SIZE)
     {   
         for (int i=0; i<size_buf; i++)
         {   
            buffer[end_index] = *data++;
                
            end_index = (end_index+1) % BUFFER_SIZE;
            amount_items++;            
         }
        
     }

     /* Test inserted*/
     for (int x=0; x < amount_items ; x++)
     {  
        cout << "buffer[" << x << "] = " << buffer[x] << endl;
     }
     cout << "amount_itens = " << amount_items << endl;

     return 1;  
 }


/**
 * @brief The function read multiple elements from internal buffer
 * @param int *buff - Pointer to ring buffer
 * @param unsigned int num_elements sizebuf - The size of the allocated 
 *                 ring buffer to copy to *buff
 * @return bool - (0) if in case of error and if buffer is empty
 *                (1) if data was inserted
 **/
bool CircularBuffer::Dequeue(int* buff, unsigned int num_elements)
{   
    int* ptr = buff;

     if (buffer == NULL || buff == NULL || ptr == NULL) return 0;
   
     if (CircularBuffer::IsEmpty() || num_elements == 0) return 0;

     for (int i =0; ( i < num_elements) && amount_items >= 0;  i++)
     {
         *ptr = buffer[start_index];
         ptr++;
         start_index = (start_index+1) % BUFFER_SIZE;
         amount_items--;
     }
 }

/**
 * @brief   The function check if buffer is empty
 * @param void
 * @return bool - (0) if buffer is not empty
 *                (1) if buffer is empty = Amount itens inserted in buffer is zero
 **/
bool CircularBuffer::IsEmpty(void)
{
     return ((CircularBuffer::amount_items == 0) ? 1:0);
}    
    
/**
 * @brief   The function check if buffer is full
 * @param void
 * @return bool - (0) if buffer is not full
 *                (1) if buffer is full = Amount itens inserted in buffer is equal buffer size
 **/
bool CircularBuffer::IsFull(void)
{
     return ((CircularBuffer::amount_items == BUFFER_SIZE) ? 1:0);
}



