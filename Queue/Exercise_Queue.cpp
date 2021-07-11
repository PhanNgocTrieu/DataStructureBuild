/*Bạn có một chuỗi ký tự. Hãy lấy ký tự ở đầu của chuỗi và thêm nó vào cuối chuỗi. Hãy cho tôi thấy sự thay đỗi của chuỗi sau khi thực hiện hành động trên N lần. */


/* Ý tưởng: Chuỗi ký tự trên có thể xem xét như là một hàng đợi. Tại mỗi bước, chúng ta sẽ dequeue(xóa) phần tử ở đầu chuỗi và thực hiện enqueue(thêm) phần tử đó cuối chuỗi. Lặp lại N lần bước công việc này, chúng ta sẽ có câu trả lời */

#include <iostream>
#include <cstdio>
 
using namespace std;
 
void Enqueue(char queue[], char element, int& rear, int arraySize) {
    if(rear == arraySize)            // Queue is full
        printf("OverFlow\n");
    else {
        queue[rear] = element;    // Add the element to the back
        rear++;
    }
}
 
 
void Dequeue(char queue[], int& front, int rear) {
    if(front == rear)            // Queue is empty
        printf("UnderFlow\n");
    else {
        queue[front] = 0;        // Delete the front element
        front++;
    }
}
 
char Front(char queue[], int front) {
    return queue[front];
}
 
 
int main() {
    char queue[20] = {'a', 'b', 'c', 'd'};        
    int front = 0, rear = 4;                
    int arraySize = 20;                // Size of the array
    int N = 3;                    // Number of steps
    char ch;
    for(int i = 0;i < N;++i) {
        ch = Front(queue, front);
        Enqueue(queue, ch, rear, arraySize);
        Dequeue(queue, front, rear);
    }
    for(int i = front;i < rear;++i)
        printf("%c", queue[i]);
    printf("\n");
    return 0;
}