#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct {
	int front;
	int rear;
	int arr[MAX];
} Queue;

Queue initQueue() {
	Queue q;
	q.rear = MAX - 1;
	q.front = 0;
	return q;
}

int isEmpty(Queue q) {
	return (q.rear + 1) % MAX == q.front;
}

int isFull(Queue q) {
	return (q.rear + 2) % MAX == q.front;
}

void enqueue(Queue *q, int val) {
	if (isFull(*q)) {
		printf("error: queue full, cannot enqueue\n");
		exit(1);
	}
	
	q->rear = (q->rear + 1) % MAX;
	q->arr[q->rear] = val;
}


int dequeue(Queue *q) {
	if (isEmpty(*q)) {
		printf("error: attempted to dequeue from empty queue\n");
		exit(1);
	}
	
	int v = q->arr[q->front];
	
	q->front = (q->front + 1) % MAX;
	
	return v;
}

void print(Queue q) {
	if (isEmpty(q)) {
		printf("\n");
		return;
	}
	int i = q.front;
	
	while (1) {
		printf("%d", q.arr[i]);
		if (i == q.rear) break;
		printf(", ");
		i = (i + 1) % MAX;
	}
	printf("\n");
}

int main() {
	int N;
	printf("Enter number of items: ");
	scanf("%d", &N);
	
	Queue nums = initQueue();
	for (int i = 0; i < N; i++) {
		int num;
		printf("Enter item: ");
		scanf("%d", &num);
		
		enqueue(&nums, num);
	}
	
	
	printf("Queue: ");
	print(nums);
	printf("\n");
	
	Queue posQ = initQueue();
	Queue negQ = initQueue();
	
	while (!isEmpty(nums)) {
		int v = dequeue(&nums);
		
		if (v > 0) enqueue(&posQ, v);
		else enqueue(&negQ, v);
	}
	
	printf("Positive Queue: ");
	print(posQ);
	printf("Negative Queue: ");
	print(negQ);
	
	return 0;
}
