//queue.h
#ifndef QUEUE_H_
#define QUEUE_H_


/* User Configuration */
//Select element type (uint8_t, uint16_t, uint32_t,.... )
//#define elementType f32
typedef f32  elementType ; 

//create buffer
#define SIZE 5

elementType buff[SIZE];


typedef struct Queue_t Queue_Buff_t;
typedef Queue_Buff_t*  QueueHandle_t ; // Incomplete type


typedef enum{
	Q_no_error,
	Q_full,
	Q_empty,
	Q_NULL
}Queue_status;

//Queue APIs
Queue_status QUEUE_init(QueueHandle_t me , elementType * buf, u8 length);
Queue_status QUEUE_enqueue(QueueHandle_t me , elementType item);
Queue_status QUEUE_dequeue(QueueHandle_t me , elementType* item);

Queue_status QUEUE_isFull(QueueHandle_t me );
void QUEUE_print(QueueHandle_t me );
	
#endif /* QUEUE_H_ */