#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    node* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* temp = head;
	char* myStr = (char*)malloc((length(head)+1)*sizeof(char));
	int i = 0;
	while (temp!=NULL){
		myStr[i] = temp->letter;
		i++;
		temp = temp->next;
	}
	myStr[i] = '\0';
	return myStr;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* temp = *pHead;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;
	if (temp==NULL){
		*pHead = newNode;
		return;
	}
	while (temp!=NULL){
		if (temp->next==NULL){
			temp->next = newNode;
			return;
		}
		temp = temp->next;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* temp = *pHead;
	while (temp!=NULL){
		node* toDelete;
		toDelete = temp;
		temp = temp->next;
		free(toDelete);
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}