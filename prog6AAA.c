
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char usn[20], name[50], program[30], phone[15];
    int sem;
    struct Student *next;
};

typedef struct Student* NODE;
NODE head = NULL;

// CREATE NODE
NODE create() {
    NODE p = malloc(sizeof(struct Student));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter USN, Name, Programme, Semester, Phone:\n");
    scanf("%19s %49s %29s %d %14s",
          p->usn, p->name, p->program, &p->sem, p->phone);

    p->next = NULL;
    return p;
}

// CREATE LIST (FRONT INSERTION)
void createList(int n) {
    NODE p;
    for (int i = 0; i < n; i++) {
        p = create();
        p->next = head;
        head = p;
    }
}

// DISPLAY AND COUNT
void display() {
    NODE temp = head;
    int count = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("\nUSN: %s | Name: %s | Programme: %s | Sem: %d | Phone: %s\n",
               temp->usn, temp->name, temp->program,
               temp->sem, temp->phone);

        count++;
        temp = temp->next;
    }

    printf("\nTotal students = %d\n", count);
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

// DELETE AT END
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE temp = head, prev = NULL;

    if (head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last student deleted\n");
}

// INSERT AT FRONT (PUSH)
void insertFront() {
    NODE p = create();
    p->next = head;
    head = p;
}

// DELETE AT FRONT (POP)
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE temp = head;
    head = head->next;
    free(temp);

    printf("First student deleted\n");
}

// MAIN MENU
int main() {
    int ch, n;

    while (1) {
        printf("\n--- STUDENT DATABASE ---\n");
        printf("1. Create List\n");
        printf("2. Display and Count\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front (PUSH)\n");
        printf("6. Delete at Front (POP)\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);
                if (n > 0)
                    createList(n);
                break;

            case 2: display(); break;
            case 3: insertEnd(); break;
            case 4: deleteEnd(); break;
            case 5: insertFront(); break;
            case 6: deleteFront(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
