#include <stdio.h>
#define MAX 100

struct Employee {
    int key;
    int used;
};

struct Employee ht[MAX];
int m;

int hash(int key)
{
    return key % m;
}

void insert(int key)
{
    int index = hash(key);

    if (ht[index].used == 0)
    {
        ht[index].key = key;
        ht[index].used = 1;
    }
    else
    {
        int i = (index + 1) % m;
        while (i != index)
        {
            if (ht[i].used == 0)
            {
                ht[i].key = key;
                ht[i].used = 1;
                return;
            }
            i = (i + 1) % m;
        }
        printf("Hash Table is full. Cannot insert %d\n", key);
    }
}

void display()
{
    int i;
    printf("\nHash Table Contents:\n");
    for (i = 0; i < m; i++)
    {
        if (ht[i].used)
            printf("Address %02d : %d\n", i, ht[i].key);
        else
            printf("Address %02d : ---\n", i);
    }
}

int main()
{
    int n, key, i;

    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
        ht[i].used = 0;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
