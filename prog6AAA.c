
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50], dept[30], designation[30], contact[15];
    struct Employee *next;
};

typedef struct Employee* NODE;
NODE head = NULL;

// CREATE NODE
NODE create() {
    NODE p = malloc(sizeof(struct Employee));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter Employee ID: ");
    scanf("%d", &p->id);

    printf("Enter Name, Department, Designation, Contact:\n");
    scanf("%49s %29s %29s %14s",
          p->name, p->dept, p->designation, p->contact);

    p->next = NULL;
    return p;
}

// INSERT AT FRONT
void insertFront() {
    NODE p = create();

    p->next = head;
    head = p;
}

// INSERT AT END
void insertEnd() {
    NODE p = create();

    if (head == NULL) {
        head = p;
        return;
    }

    NODE temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
}

// DELETE AT FRONT
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE temp = head;
    head = head->next;

    free(temp);
    printf("Employee deleted\n");
}

// DELETE AT END
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE temp = head, prev = NULL;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Employee deleted\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Employee deleted\n");
}

// DISPLAY
void display() {
    NODE temp = head;
    int count = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("\nEmployee ID: %d", temp->id);
        printf("\nName: %s", temp->name);
        printf("\nDepartment: %s", temp->dept);
        printf("\nDesignation: %s", temp->designation);
        printf("\nContact: %s\n", temp->contact);

        count++;
        temp = temp->next;
    }

    printf("\nTotal Employees: %d\n", count);
}

// MAIN MENU
int main() {
    int ch;

    while (1) {
        printf("\n--- EMPLOYEE RECORD MANAGEMENT ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Front\n");
        printf("4. Delete at End\n");
        printf("5. Display Employees\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertFront(); break;
            case 2: insertEnd(); break;
            case 3: deleteFront(); break;
            case 4: deleteEnd(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
