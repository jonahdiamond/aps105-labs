#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
/* DO NOT EDIT THE LINES BELOW */
#define STRING_MAX 1024
typedef struct node {
    char *name;
    int lines;
    int runtime;
    int memory_usage;
    struct node *next;
} Node;
typedef struct linked_list {
    Node *head;
} LinkedList;
void readInputString(char *, int);
void readInputNumber(int *);
void readInputChar(char *);
LinkedList * newList();
char getCommand();
void handleInsert(LinkedList *);
void handleDelete(LinkedList *);
void handleSearch(LinkedList *);
void handlePrint(LinkedList *);
void handleQuit(LinkedList *);
int main() {
    LinkedList *list = newList();
    char command = '\0';
    printf("Experimental database entry\n");
    while (command != 'Q') {
        command = getCommand();
        switch (command) {
            case 'I':
                handleInsert(list);
                break;
            case 'D':
                handleDelete(list);
                break;
            case 'S':
                handleSearch(list);
                break;
            case 'P':
                handlePrint(list);
                break;
            case 'Q':
                handleQuit(list);
                break;
        }
    }
    free(list);
    return 0;
}
/* DO NOT EDIT THE LINES ABOVE */
/*void printList(LinkedList *list) {
    Node *current = list->head;
    printf("Current entries:\n");
    while (current != NULL) {
        printf("%s\t%d\t%d\t%d\n", current->name, current->lines, current->runtime, current->memory_usage);
        current = current->next;
    }
    printf("\n");
}*/
void handleInsert(LinkedList *list) {
    printf("\n");
    // place your code to handle the insert command here
    //prompt user for file name and size
    //prompt user for program's runtime and memory usage

    //initialize variables
    int length = 0, lines = 0, runTime = 0, storage = 0;
    
    //get file name length
    printf("Number of characters in file name: ");
    readInputNumber(&length); 
    //add 1 to file name bc of <enter>
    length++;

    //get file name
    char* fileName = (char*)malloc(length * sizeof(char));
    printf("File name: ");
    readInputString(fileName, length);
    
    //get number of lines in file
    printf("Number of lines in CSV file: ");
    readInputNumber(&lines);

    //get experimental runtime in milliseconds
    printf("Experiment runtime (ms): ");
    readInputNumber(&runTime);

    //get experimental memory storage in Bytes
    printf("Experiment memory usage (B): ");
    readInputNumber(&storage);
    

    //make into node
    Node *newNode = (Node*) malloc((sizeof(Node)));

    //Node newNode;
    // newNode->name = fileName;
    // newNode->lines = lines;
    // newNode->runtime = runTime;
    // newNode->memory_usage = storage;

    //if empty list
    if (list->head == NULL){
        newNode->next = NULL;
        list->head = newNode;
        //printList(list);
        return;
    }
    
    //initialize node pointer to use for loops
    Node *current = list->head;

    //find out if file already exists
    while (current != NULL){
        if (strcmp(current->name,fileName) == 0){
            printf("\nAn entry with that file name already exists.\n");
            free(fileName);
            fileName = NULL;
            free(newNode);
            newNode = NULL;
            //printList(list);
            return;
        }
        current = current->next;
    }
    
    //reset current
    current = list->head;
    
    //add into linked list
    while (current != NULL){
        //empty linked list
        if (list->head == NULL){
            newNode->next = NULL;
            list->head = newNode;

            /*printf("\nnewNode: %s", newNode->name);
            printf("\ntail: %s", newNode->next);*/

            //free dynamically allocated memory
            /*free(newNode);
            newNode = NULL;
            free(fileName);
            fileName = NULL;*/
            //printList(list);
            return;
        }
        //linked list with one node
        if (list->head == current && current->next == NULL){
            
            //if name of new experiment is alphabetically first
            if (strcmp(current->name, fileName) > 0){
                newNode->next = current;
                list->head->next = newNode;
                /*free(fileName);
                fileName = NULL;*/
                //printList(list);
                return;
            } else { //if name of new experiment is alphabetically second
                newNode->next = NULL;
                current->next = newNode;
                /*free(fileName);
                fileName = NULL;*/
                //printList(list);
                return;
            }
        }
        // if here, must be multiple nodes in list

        //if next node is greater, insert here
        if (strcmp(current->next->name, fileName) > 0){
            newNode->next = current->next;
            current->next = newNode;
            /*free(fileName);
            fileName = NULL;*/
            //printList(list);
            return;
        }
        //if still gotta iterate, keep going
        current = current->next;
    }
}
void handleDelete(LinkedList *list) {                                               //infinite loop in delete!!!
    printf("\n");
    // place your code to handle the delete command here
    //if list is empty
    if (list->head == NULL){
        printf("There are no data entries.\n");
        //printList(list);
        return;
    }
    //if we're here, we know the list is not empty

    //get file name to delete
    char* fileToDelete = (char*)malloc(STRING_MAX * sizeof(char));
    printf("Enter file name to delete: ");
    readInputString(fileToDelete, STRING_MAX);

    //create a node pointer to loop through list
    Node *nodeToDelete = list->head;

    //create a node before deleted node to properly attach the previous node when removing a node
    Node *nodeBeforeToDelete = NULL;

    //if list has one node only
    if (strcmp(list->head->name, fileToDelete) == 0 && list->head->next == NULL){
        list->head = list->head->next;
        printf("Deleting entry for CSV file <%s>", fileToDelete);
        
        //delete file we're supposed to delete
        //delete pointer
        free(nodeToDelete);
        nodeToDelete = NULL;
        printf("\n");
        //printList(list);
        return;
    } 

    //loop thru linked list until we find the node or until we've finished
    while (nodeToDelete != NULL && strcmp(nodeToDelete->name, fileToDelete) != 0){
        nodeBeforeToDelete = nodeToDelete;
        nodeToDelete = nodeToDelete->next;
    }

    //if we found the node, remove it
    if (nodeToDelete != NULL){
        //if node to delete is head
        if (nodeToDelete == list->head){
            list->head = nodeToDelete->next;
        } else {
            nodeBeforeToDelete->next = nodeToDelete->next;                      //seg fault happening here
        }
        printf("Deleting entry for CSV file <%s>", fileToDelete);
        
        //delete file we're supposed to delete
        //delete pointer
        free(nodeToDelete);
        nodeToDelete = NULL;
        printf("\n");
        //printList(list);
        return;
    }


     //if filename not found in list
    printf("An entry for file <%s> does not exist.\n", fileToDelete);
    //printList(list);
    return;
}
void handleSearch(LinkedList *list) {
    printf("\n");
    // place your code to handle the search command here

    //prompt user for file name to find
    char* fileToFind = (char*)malloc(STRING_MAX * sizeof(char));
    printf("Enter file name to find: ");
    readInputString(fileToFind, STRING_MAX);
    
    //if list is empty
    if (list->head == NULL){
        printf("An entry for file <%s> does not exist.\n", fileToFind);
        //printList(list);
        return;
    }

    //if list has one node
    if (list->head != NULL && list->head->next == NULL){
        if (strcmp(list->head->name, fileToFind) == 0){
            printf("File <%s>\n", list->head->name);
            printf("Lines: %d\n", list->head->lines);
            printf("Runtime (ms): %d\n", list->head->runtime);
            printf("Memory usage (B): %d\n", list->head->memory_usage);
            printf("Throughput: %.2lf", ((double)list->head->lines/(double)list->head->runtime)*1000);
            printf("\n");
            free(fileToFind);
            fileToFind = NULL;
            //printList(list);
            return;
        }
    }

    //create node to find
    Node *nodeToSearch = list->head;

    //loop thru list to find node
    while (nodeToSearch != NULL){
        //if we found the node, exit
        if (strcmp(nodeToSearch->name, fileToFind) == 0){
            break;
        }
        nodeToSearch = nodeToSearch->next;
    }
    if (nodeToSearch != NULL){
        printf("File <%s>\n", nodeToSearch->name);
        printf("Lines: %d\n", nodeToSearch->lines);
        printf("Runtime (ms): %d\n", nodeToSearch->runtime);
        printf("Memory usage (B): %d\n", nodeToSearch->memory_usage);
        printf("Throughput: %.2lf", ((double)nodeToSearch->lines/(double)nodeToSearch->runtime)*1000);
        printf("\n");
        free(fileToFind);
        fileToFind = NULL;
        //printList(list);
        return;
    }

    //we only get here if list is not empty
    printf("An entry for file <%s> does not exist.\n", fileToFind);
    free(fileToFind);
    fileToFind = NULL;
    //printList(list);
    return;
}
void handlePrint(LinkedList *list) {
    printf("\n");
    // place your code to handle the print command here
    printf("Data entries:\n");
    
    //if no elements in list
    if (list->head == NULL){
        printf("There are no data entries.\n");
        //printList(list);
        return;
    }
    //printf("\n");

    //node to loop with
    Node *nodeToPrint = list->head;
    //nodeToPrint->next = NULL;

    //loop thru list and print each element
    while (nodeToPrint != NULL){
        printf("\n");
        printf("File <%s>\n", nodeToPrint->name);
        printf("Lines: %d\n", nodeToPrint->lines);
        printf("Runtime (ms): %d\n", nodeToPrint->runtime);
        printf("Memory usage (B): %d\n", nodeToPrint->memory_usage);
        printf("Throughput: %.2lf\n", ((double)nodeToPrint->lines/(double)nodeToPrint->runtime)*1000);
        nodeToPrint = nodeToPrint->next;
    }
}
void handleQuit(LinkedList *list) {
    // place your code to handle the quit command here

    //if nothing to delete
    if (list->head == NULL){
        return;
    }

    //if one node in list
    if (list->head != NULL && list->head->next == NULL){
        printf("Deleting entry for CSV file <%s>", list->head->name);
        free(list->head);
        list->head = NULL;
        return;
    }

    //if multiple nodes in list

    //initialize node pointer to use for loops
    Node *current = list->head;

    //find out if file already exists
    while (current != NULL){
        printf("Deleting entry for CSV file <%s>\n", current->name);
        free(current);
        current = current->next;
    }
    
}
/* DO NOT EDIT THE LINES BELOW */
void readInputString(char *str, int length) {
    int i = 0;
    char c;
    while (i < length && (c = getchar()) != '\n') {
        str[i++] = c;
    }
    str[i] = '\0';
}
void readInputNumber(int *number) {
    char buf[STRING_MAX];
    readInputString(buf, STRING_MAX);
    *number = (int)strtol(buf, (char **)NULL, 10);
}
void readInputChar(char *character) {
    char buf[2];
    readInputString(buf, 3);
    *character = buf[0];
}
LinkedList * newList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}
char getCommand() {
    char command;
    printf("\nSupported commands are:\n");
    printf(" I - Insert\n");
    printf(" D - Delete\n");
    printf(" S - Search\n");
    printf(" P - Print\n");
    printf(" Q - Quit\n");
    printf("\nPlease select a command: ");
    readInputChar(&command);
    while (command != 'I' && command != 'D' && command != 'S' && command != 'P'
        && command != 'Q') {
        printf("Invalid command <%c>, please select a command: ", command);
        readInputChar(&command);
    }
    return command;
}
/* DO NOT EDIT THE LINES ABOVE */
