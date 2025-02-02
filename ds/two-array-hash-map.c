#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100

typedef struct
{
    char *keys[CAPACITY];
    void *values[CAPACITY];
    size_t size;
} HashMap;

HashMap *create_hash_map()
{
    HashMap *hm = malloc(sizeof(HashMap));

    if (hm == NULL) {
        return NULL;
    }

    for (int i = 0; i < CAPACITY; i++) {
        hm->keys[i] = NULL;
        hm->values[i] = NULL;
    }

    hm->size = 0;

    return hm;
}

void set(HashMap *hm, char *key, void *value)
{
    if (hm->size >= CAPACITY)
    {
        return;
    }

    for (int i = 0; i < hm->size; i++)
    {
        if (strcmp(hm->keys[i], key) == 0)
        {
            hm->values[i] = value;
            return;
        }
    }

    hm->keys[hm->size] = key;
    hm->values[hm->size] = value;
    hm->size++;
}

void *get(HashMap *hm, char *key) {
    for (int i = 0; i < hm->size; i++)
    {
        if (strcmp(hm->keys[i], key) == 0)
        {
            return hm->values[i];
        }
    }

    return NULL;
}

int main()
{
    HashMap *hm = create_hash_map();
    int v = 1;

    set(hm, "key", &v);
    set(hm, "key", &v);

    printf("%d\n", *((int *)get(hm, "key")));
}
