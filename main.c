//main.c

#include <stdio.h>
#include "LIB/STD_TYPES.h"
#include "queue.h"

void main()
{
	elementType temp=0;
	QueueHandle_t Queue_FloatNums ;

	//initial queue
	if( QUEUE_init( Queue_FloatNums , buff , SIZE) == Q_no_error)
		printf("QUEUE Initial is.... Done \n");

	// Enqueue
	for(int i=0;i<7;i++)
	{
		printf("QUEUE Enqueue (%f) \n",i+0.1);
		if(QUEUE_enqueue(Queue_FloatNums, i+0.1 ) == Q_no_error)
				printf("\t QUEUE Enqueue is.... Done \n");
		else
			printf("\t QUEUE Enqueue is.... failed \n");
	}

	QUEUE_print(Queue_FloatNums);

	//Dequeue

	for(int i=0;i<8;i++)
	{
		if(QUEUE_dequeue(Queue_FloatNums,&temp) == Q_no_error)
			printf("\t QUEUE Dequeue (%f) \n",temp);
		else
			printf("\t QUEUE Dequeue is.... failed \n");
	}

	QUEUE_print(Queue_FloatNums);

}
