static unsigned long int next = 1;

int rand(void)
{
    next = next * 1103515245 + 12345;
    return (next % 7);
}

void srand (unsigned int seed) {
    next = seed;
}

unsigned int hash (const char* word)
{
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = 31*hash + word[i];
    }
    return hash % (sizeof(unsigned int));
}