#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MININT -0xffffffff

struct LinkNode {
    ElementType value;
    struct LinkNode *next;
};

typedef struct LinkNode *List;
typedef struct LinkNode *Node;

List InsertSortForList(List list);

int BucketSort(ElementType *array, int size);

int main(int argc, char *argv[]) {
    return 0;
}

List InsertSortForList(List list) {
    if (list == NULL) {
        return NULL;
    }

    int size = 0;
    for (Node i = list; i != NULL; i = i->next) {
        size++;
    }

    List newListHead = (List)malloc(sizeof(List));
    if (newListHead == NULL) {
        return NULL;
    }
    newListHead->value = MININT;

    Node pre = NULL, current = NULL;
    for (Node i = list; i != NULL; i = i->next) {
        current = pre = newListHead;

        while (current->next != NULL) {
            pre = current;
            current = current->next;

            if (pre->value < i->value && i->value <= current->value) {
                Node ctx = (Node)malloc(sizeof(Node));
                if (ctx == NULL) {
                    return NULL;
                }

                ctx->value = i->value;
                pre->next = ctx;
                ctx->next = current;
                break;
            }
        }

        if (current->next == NULL) {
            Node ctx = (Node)malloc(sizeof(Node));
            if (ctx == NULL) {
                return NULL;
            }

            ctx->value = i->value;
            current->next = ctx;
        }
    }

    return newListHead->next;
}

int BucketSort(ElementType *array, int size) {
    int bucketNum = 10;
    List bucket[bucketNum];

    for(int i = 0; i < size; i++) {
        
    }
}