#include<iostream>
#define SIZE 5
typedef int element;
element ouputerror = -100000000;
typedef struct {
    element arr[SIZE];
    int front, rear;
}RoundQueue;

RoundQueue* Create(){
    RoundQueue *queue = new RoundQueue;
    return queue;
}

void init(RoundQueue* queue){
    queue->front = queue->rear = 0;
}

bool is_empty(RoundQueue* queue){
    return queue->front == queue->rear;
}

bool is_full(RoundQueue* queue){
    return (queue->rear+1) % SIZE == queue->front;
}
void enqueue(RoundQueue* queue, element item){
    if(!is_full(queue)){
        queue->rear = (queue->rear + 1) % SIZE;
        queue->arr[queue->rear] = item;
        printf("인큐완료\n");
    }
    else{
        printf("꽉찬 큐\n");
    }
}
element dequeue(RoundQueue* queue){
    if(!is_empty(queue)){
        queue->front = (queue->front+1) % SIZE;
        return queue->arr[queue->front];
    }
    printf("빈큐\n");
    return ouputerror;
}
element peek(RoundQueue* queue){
    if(!is_empty(queue)){
        return queue->arr[(queue->front+1) % SIZE];
    }
    return ouputerror;
}

void printqueue(RoundQueue* queue){
    int front = (queue->front + 1) % SIZE;
    int rear = queue->rear;
    while(!(front == (rear+1)%SIZE)){
        printf("%d |", queue->arr[front]);
        front = (front + 1) % SIZE;
    }
    printf("\n");
}
int main(){
    RoundQueue* queue = Create();
    init(queue);
    int cursor = 0;
    while(cursor != 5){
        printf("1. 인큐\n2. 디큐\n3.피크\n4. 출력\n5. 종료\n==>");
        scanf("%d", &cursor);
        if(cursor == 1){
            int item;
            scanf("%d", &item);
            enqueue(queue, item);
        }
        else if(cursor == 2){
            printf("디큐값: %d\n", dequeue(queue));
        }
        else if(cursor == 3){
            printf("피크값: %d\n", peek(queue));
        }
        else if(cursor == 4){
            printqueue(queue);
        }
    }
}
