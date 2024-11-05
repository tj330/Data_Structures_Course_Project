#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int size=10, front=-1, rear=-1, i, loc, top=-1;
char d[64];
struct PQ {
    char item[100];
    int priority;
} pq[20];

struct Stack {
    char item[100];
    char date[50];
} s[20];

char*  getDate() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    size_t ret = strftime(d, sizeof(d), "%c", tm);
    assert(ret);
    return d;
}

void push(char item[], char date[]) {
    top++;
    strcpy(s[top].item, item);
    strcpy(s[top].date, date);
}

void pop() {
    if (top == -1) {
    	printf("\tNo task to complete\n");
    }
    printf("\tDeleted completed tasks history\n");
    top = -1;
}

void sDisplay() {
    if (top == -1) {
    	printf("\tHistory is empty\n");
	return;
    }
    printf("\tCompleted tasks: \n\n");

    for (int i=0; i<=top; i++) {
    	printf("\tTask %s completed at %s\n", s[i].item, s[i].date); 
    }
}

void enqueue(char item[], int priority) {
    if (front == -1) {
    	front = rear = 0;
	strcpy(pq[rear].item, item);
	pq[rear].priority = priority;
    }
    else {
	if (rear == size-1) {
	    for (i=front; i<=rear; i++) {
		pq[i-1] = pq[i];
	    }
	    rear--;
	    front--;
	}

	for (i=rear; i>=front; i--) {
	    if (pq[i].priority < priority) {
	        break;
	    }
        }


	loc = i + 1;

	for (i=rear; i>=loc; i--) {
	    pq[i+1] = pq[i];
	}

	strcpy(pq[loc].item, item);
	pq[loc].priority = priority;
	rear++;
    }
}

void dequeue() {
    if (front == -1) {
    	printf("No tasks to complete\n");	
    }
    
    else if (front == rear) {
	char* date = getDate();
	push(pq[front].item, date);
	printf("\tTask %s completed\n",pq[front].item);
    	front = -1;
	rear = -1;
    }

    else {
	char* date = getDate();
	push(pq[front].item, date);
	printf("\tTask %s completed\n",pq[front].item);
    	front++;
    }
}

void display() {
    if (front == -1) {
    	printf("\tNo tasks found!\n");
    }
    else {
    	for (i=front; i<=rear; i++) {
	    printf("%s (priority:%d)\n", pq[i].item, pq[i].priority);
	}
    }
}


void main() {
    char i[100];
    int ch, priority;
    printf("\n##############################################\n\n");
    printf("\tWelcome to the TodoList App\n");
    printf("\n##############################################\n");
    do {
    	printf("\n1. Add new task\n");
    	printf("2. View tasks\n");
    	printf("3. Complete task\n");
    	printf("4. View Completed tasks history\n");
   	printf("5. Delete completed tasks history\n");
    	printf("6. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &ch);
	switch(ch) {
	    case 1:
		printf("Enter the task: ");
		getchar();
		fgets(i, sizeof(i), stdin);
		size_t len = strcspn(i, "\n");
		i[len] = '\0';		
		printf("Enter the priority: ");
		scanf("%d", &priority);
		enqueue(i, priority);
		printf("\n\nTask added succesfully\n");
		break;
	    case 2:
		printf("\n##############################################\n\n");
		printf("\tIncomplete tasks: \n\n");
		display();
		printf("\n##############################################\n");
		break;
	    case 3:
		printf("\n################################################################\n\n");
		dequeue();
		printf("\n################################################################\n");
		break;
	    case 4:
		printf("\n#####################################################################################\n\n");
		sDisplay();
		printf("\n#####################################################################################\n");
		break;
	    case 5:
		printf("\n##############################################\n\n");
		pop();
		printf("\n##############################################\n");
		break;
	    case 6:
		printf("Exiting....");
		break;
	    default:
		printf("Invalid choice\n");
		break;
	}
    } while(ch!=6);
}
