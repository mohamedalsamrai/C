#include <stdio.h>

typedef struct Node {
    char name;
    int SD;
    struct Node *previous;
} Node;

int search(char name, Node list[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (name == list[i].name)
        {
            Node *cur = &list[i];
            while (cur != NULL)
            {
                sum += cur->SD;
                cur = cur->previous;
            }
            break;
        }

    }
    return sum;
}

int main(void)
{
    Node nodeA = {'A', 0, NULL};
    Node nodeB = {'B', 2, &nodeA};
    Node nodeE = {'E', 8, &nodeB};
    Node nodeD = {'D', 7, &nodeB};
    Node nodeF = {'F', 9, &nodeD};
    Node nodeC = {'C', 12, &nodeF};
    Node nodes[6] = {nodeA, nodeB, nodeC, nodeD, nodeE, nodeF};

    int r = search('B', nodes, 6);
    printf("sum = %d\n", r); 
    return 0;
}
