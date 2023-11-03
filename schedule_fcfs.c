

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Task struct
typedef struct {
    char name[10];
    int priority;
    int BurstTime;
} Task;

// linked lost struct
typedef struct Node {
    Task task;
    struct Node *next;
} Node;

// Node Creation
Node *createNode(Task task) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->task = task;
    newNode->next = NULL;
    return newNode;
}

// Adding task in the list
void addTask(Node **head, Task task) {
    Node *newNode = createNode(task);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// scheduling fcfs
void schedule(Node *head) {
    Node *current = head;
    int CurrentTime = 0;
    float total_WaitTime = 0, total_TurnaroundTime = 0, total_ResponseTime = 0;
    
    while (current != NULL) {
        printf("Running task = [%s] [%d] [%d] for %d units.\n", current->task.name, current->task.priority, current->task.BurstTime, current->task.BurstTime);
        
        total_WaitTime += CurrentTime;
        total_ResponseTime += CurrentTime;
        total_TurnaroundTime += current->task.BurstTime + CurrentTime;
        
       CurrentTime += current->task.BurstTime;
        current = current->next;
    }
    
    float avg_wait_time = total_WaitTime / 8; // Modify this according to the number of tasks
    float avg_turnaround_time =  total_TurnaroundTime / 8; // Modify this according to the number of tasks
    float avg_response_time =  total_ResponseTime / 8; // Modify this according to the number of tasks
    
    printf("Average waiting time = %.2f\n", avg_wait_time);
    printf("Average turnaround time = %.2f\n", avg_turnaround_time);
    printf("Average response time = %.2f\n", avg_response_time);
}

int main() {
    // We have these tasks
    Task tasks[] = {
        {"T1", 4, 20},
        {"T2", 3, 25},
        {"T3", 3, 25},
        {"T4", 5, 15},
        {"T5", 5, 20},
        {"T6", 1, 10},
        {"T7", 3, 30},
        {"T8", 10, 25}
    };
    
    // Linked list of these tasks
    Node *head = NULL;
    for (int i = 0; i < sizeof(tasks) / sizeof(tasks[0]); i++) {
        addTask(&head, tasks[i]);
    }

    // Simulatation of fcfs scheduling algorithm
    schedule(head);

    return 0;
}
