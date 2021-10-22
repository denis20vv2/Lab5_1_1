#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue> // очередь
#define SIZE 40


using namespace std;
struct queue_str {
    int items[SIZE];
    int front;
    int rear;
};
struct queue_str* createQueue();
void enqueue(struct queue_str* q, int);
int dequeue(struct queue_str* q);
void display(struct queue_str* q);
int isEmpty(struct queue_str* q);
void printQueue(struct queue_str* q);
void BFS2(int mas[7][7]);

int main1();

void printGraph(struct Graph* graph);
void BFS2(int mas[7][7]);






void BFS2(int mas[7][7])
{
    struct queue_str* q = createQueue();
    
    int nodes[7]; // вершины графа
    for (int i = 0; i < 7; i++)
        nodes[i] = 0; // исходно все вершины равны 0
    enqueue(q, 0); // помещаем в очередь первую вершину
    while (!isEmpty(q))
    { // пока очередь не пуста
        printQueue(q);
        int node = dequeue(q);
       
        nodes[node] = 2; // отмечаем ее как посещенную
        for (int j = 0; j < 7; j++)
        { // проверяем для нее все смежные вершины
            if (mas[node][j] == 1 && nodes[j] == 0)
            { // если вершина смежная и не обнаружена
                enqueue(q, j); // добавляем ее в очередь
                nodes[j] = 1; // отмечаем вершину как обнаруженную
            }
        }
        cout << node + 1 << endl; // выводим номер вершины
    }
}





struct queue_str* createQueue() {
    struct queue_str* q = (struct queue_str*)malloc(sizeof(struct queue_str));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(struct queue_str* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
void enqueue(struct queue_str* q, int value) {
    if (q->rear == SIZE - 1)
        //printf("\nОчередь заполнена!!");
        printf("");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(struct queue_str* q) {
    int item;
    if (isEmpty(q)) {
        //printf("Очередь пуста");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            //printf("Сброс очереди");
            q->front = q->rear = -1;
        }
    }
    return item;
}
void printQueue(struct queue_str* q) {
    int i = q->front;
    if (isEmpty(q)) {
        // printf("Очередь пуста");
    }
    else {
        // printf("\nОчередь содержит \n");
        for (i = q->front; i < q->rear + 1; i++) {
            // printf("%d ", q->items[i]);
        }
    }
}



int main()
{
    
    int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
    { 1, 0, 1, 1, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0 } };

   

    BFS2(mas);
    return 0;
}


