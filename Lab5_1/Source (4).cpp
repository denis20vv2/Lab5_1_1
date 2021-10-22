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
#include <queue> 
#include <ctime>
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
void BFS1(int mas[7][7]);

int main1();
struct node
{
    int vertex;
    struct node* next;
};
struct node* createNode(int);
struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void bfs(struct Graph* graph, int startVertex);
int main()
{
    setlocale(LC_ALL, "Rus");
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    bfs(graph, 0);

    main1();

    return 0;
}
void bfs(struct Graph* graph, int startVertex) {
    struct queue_str* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Посетил %d\n", currentVertex);

        struct node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

struct node* createNode(int v)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));


    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
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



//////////////////////////////////////////////



int main1()
{

    int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
    { 1, 0, 1, 1, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0 } };
    printf("\nобход матрици смежности \n");
    BFS1(mas);
    return 0;
    
}
void BFS1(int mas[7][7])
{
    queue<int> Queue;
    int nodes[7]; // вершины графа
    for (int i = 0; i < 7; i++)
        nodes[i] = 0; // исходно все вершины равны 0
    Queue.push(0); // помещаем в очередь первую вершину
    while (!Queue.empty())
    { // пока очередь не пуста
        int node = Queue.front(); // извлекаем вершину
        Queue.pop();
        nodes[node] = 2; // отмечаем ее как посещенную
        for (int j = 0; j < 7; j++)
        { // проверяем для нее все смежные вершины
            if (mas[node][j] == 1 && nodes[j] == 0)
            { // если вершина смежная и не обнаружена
                Queue.push(j); // добавляем ее в очередь
                nodes[j] = 1; // отмечаем вершину как обнаруженную
            }
           // int tim = clock();
        }
        
        cout << node + 1 << endl; // выводим номер вершины
    }
    printf("Время выполнения: %d", clock());
}
