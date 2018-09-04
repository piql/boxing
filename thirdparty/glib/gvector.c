#include "gvector.h"
#include <string.h> // memcpy
#include "boxing/log.h"

gvector * gvector_create(size_t item_size, size_t items_num)
{
    gvector * new_vector = malloc(sizeof(gvector));
    gvector_create_inplace(new_vector, item_size, items_num);
    return new_vector;
}

gvector * gvector_create_char(size_t items_num, char value)
{
    gvector * new_vector = malloc(sizeof(gvector));
    gvector_create_inplace(new_vector, 1, items_num);
    memset(new_vector->buffer, value, new_vector->size);
    return new_vector;
}

gvector * gvector_create_char_no_init(size_t items_num)
{
    gvector * new_vector = malloc(sizeof(gvector));
    gvector_create_inplace(new_vector, 1, items_num);
    return new_vector;
}

gvector * gvector_create_pointers(size_t items_num)
{
    gvector * new_vector = malloc(sizeof(gvector));
    gvector_create_inplace(new_vector, sizeof(void *), items_num);
    new_vector->element_free = free;
    return new_vector;
}

void gvector_free(gvector * vector)
{
    if (vector != NULL)
    {
        if (vector->element_free != NULL)
        {
            for (size_t i = 0; i < vector->size; ++i)
            {
                vector->element_free(GVECTORN(vector, void*, i));
            }
        }
        free(vector->buffer);
        free(vector);
    }
}

void gvector_create_inplace(gvector * vector, size_t item_size, size_t items_num)
{
	if (vector == NULL)
	{
		return;
	}
    vector->element_free = NULL;
    vector->size = items_num;
    vector->item_size  = item_size;
    vector->buffer = malloc(items_num * item_size);
    DFATAL(vector->buffer, "Out of memory");
}

void gvector_append(gvector * vector, unsigned int items_num)
{
    size_t new_size = vector->item_size * (vector->size + items_num);
	vector->buffer = realloc(vector->buffer, new_size);
    DFATAL(vector->buffer || items_num == 0, "Out of memory");
    vector->size += items_num;
}

void gvector_append_data(gvector * vector, unsigned int items_num, void * new_elements)
{
    size_t old_size = vector->size;
    gvector_append(vector, items_num);
    memcpy ( (char *)vector->buffer + vector->item_size * old_size, new_elements, items_num * vector->item_size);
}

void gvector_append_data_at(gvector * vector, unsigned int items_num, void * new_elements, size_t at_index)
{
    size_t old_size = vector->size;
    gvector_append(vector, items_num);
    size_t move_amount = old_size - at_index;
    char * at = (char *)vector->buffer + vector->item_size * at_index;
    if (move_amount > 0)
    {
        memmove(at + vector->item_size * items_num, at, vector->item_size *move_amount);
    }
    memcpy ( at, new_elements, items_num * vector->item_size);
}

void gvector_resize(gvector * vector, unsigned int items_num)
{
    vector->buffer = realloc(vector->buffer, vector->item_size * items_num);
    if(items_num)
    {
	DFATAL(vector->buffer, "Out of memory");
    }
    if (vector->size < items_num)
    {
        memset((char *)vector->buffer + vector->item_size * vector->size, 0, vector->item_size * (items_num - vector->size));
    }
    vector->size = items_num;
}

void gvector_swap(gvector * a, gvector * b)
{
    void * tmp_buffer = a->buffer;
    a->buffer = b->buffer;
    b->buffer = tmp_buffer;

    size_t tmp_size = a->size;
    a->size = b->size;
    b->size = tmp_size;
}

void gvector_replace(gvector * to, gvector * from)
{
    free(to->buffer);
    to->buffer = from->buffer;
    to->size = from->size;
    from->buffer = NULL;
    free(from);
}
