//  PROJECT INCLUDES
//

#include "gutils.h"

//  PRIVATE INTERFACE
//

static char symboltolower(char symbol);


// PUBLIC GUTILS FUNCTIONS
//

int lowercmp(const char * str1, const char * str2)
{
    if (symboltolower(*str1) != symboltolower(*str2))
    {
        return 0;
    }
    else if (*str1 == '\0')
    {
        return 1;
    }

    do
    {
        ++str1;
        ++str2;
        if (symboltolower(*str1) != symboltolower(*str2))
        {
            return 0;
        }
    }
    while (*str1 != '\0');

    return 1;
}

// PRIVATE GUTILS FUNCTIONS
//

static char symboltolower(char symbol)
{
    if (symbol >= 'A' && symbol <= 'Z')
    {
        return symbol - ('A' - 'a');
    }
    else
    {
        return symbol;
    }
}
