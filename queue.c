
#include <stdio.h>
#include "LIB/STD_TYPES.h"
#include "queue.h"


//QUEUE Data Types
typedef struct Queue_t{
	u8 size;
	u8 len;
	u8 count;
	elementType* base;
	elementType* back;
	elementType* front;
}Queue_Buff_t;


Queue_status QUEUE_init(QueueHandle_t me , elementType * buf, u8 length)
{
	if(buf == NULL)
		return Q_NULL;
	me->base =buf;
	me->back =buf;
	me->front =buf;
	me->size=length* sizeof(elementType) ;
	me->len=length;
	me->count=0;
	return Q_no_error;
}


Queue_status QUEUE_enqueue(QueueHandle_t me , elementType item)
{
	//check queue is valid
	if(!me->base || !me->back || !me->front)
		return Q_NULL;

	// //check queue is full
	// if(QUEUE_isFull(me) == Q_full)
		// return Q_full;

	//Enqueue Value
	//*(me->head)=item;
	
	/* Circular queue */
	if( me->back == ( me->base + me->len ) ) //to know head is MAX (0x0 + 5*1)=5
	{
		me->back = me->base;
		*(me->back)=item;
		me->back++;
		me->count=me->len;
	}
	else
	{
		*(me->back)=item;
		me->back++;
		if(me->count<5)
			me->count++;
	}
	
	return Q_no_error;
}

Queue_status QUEUE_dequeue(QueueHandle_t me , elementType* item)
{
	//check queue is valid
	if(!me->base || !me->back || !me->front)
		return Q_NULL;

	//check queue is empty
	if(me->count == 0)
		return Q_empty;
	
	//Dequeue Value
	*item = *(me->front);
	me->count--;
	
	if( me->front == ( me->base + me->len ) ) //to know head is MAX (0x0 + 5*1)=5
	{
		me->front = me->base ;
		*item = *(me->front);
		me->count--;
	}
	else
		me->front++;

	return Q_no_error;
}


Queue_status QUEUE_isFull(QueueHandle_t me )
{
	//check queue is valid
	if(!me->base || !me->back || !me->front)
		return Q_NULL;
	else if(me->count == me->len)
		return Q_full;
	else
		return Q_no_error;
}


void QUEUE_print(QueueHandle_t me )
{
	elementType* temp;
	int i;
	if(me->count == 0)
		printf("Queue is Empty");
	else{
		temp=me->front;
		printf("=====Queue print====\n");
		for(i=0 ;i<me->count;i++)
		{
			printf("\t %f \n",*temp);
			temp++;
		}
		printf("==================\n");

	}
}