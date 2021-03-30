#include <iostream>
#include <assert.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

char *m_strcpy(char *strDest, const char *strSrc)
{
    assert(strDest != NULL && strSrc != NULL);
    char *addr = strDest;
    while (*strDest = *strSrc)
    {
        strDest++;
        strSrc++;
    }
    return addr;
}

int main()
{
    char *dest = (char *)malloc(100*sizeof(char));
    cout << m_strcpy(dest, "7189413123abc123") << endl;
    strcpy(dest, "413123abc123");
    cout << strlen(dest) << endl;
}

