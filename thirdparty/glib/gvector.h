#ifndef __G_VECTOR_H__
#define __G_VECTOR_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*gvector_element_free_callback)(void * element);

typedef struct
{
    void * buffer;
    size_t size; // number of items
    size_t item_size;
    gvector_element_free_callback element_free;
} gvector;



gvector * gvector_create(size_t item_size, size_t items_num);
gvector * gvector_create_char_no_init(size_t items_num);
gvector * gvector_create_char(size_t items_num, char value);
gvector * gvector_create_pointers(size_t items_num);
void gvector_free(gvector * vector);
void gvector_create_inplace(gvector * vector, size_t item_size, size_t items_num);
void gvector_append(gvector * vector, unsigned int items_num);
void gvector_resize(gvector * vector, unsigned int items_num);
void gvector_append_data(gvector * vector, unsigned int items_num, void * new_elements);
void gvector_append_data_at(gvector * vector, unsigned int items_num, void * new_elements, size_t at_index);
void gvector_swap(gvector * a, gvector * b);
void gvector_replace(gvector * to, gvector * from);

#define GVECTORN(vector, type, n) ((type*)(vector)->buffer)[n]
#define GVECTORN8(vector, n) ((char*)(vector)->buffer)[n]
#define GVECTORN16(vector, n) ((short*)(vector)->buffer)[n]
#define GVECTORN32(vector, n) ((int*)(vector)->buffer)[n]
#define GVECTORNU8(vector, n) ((unsigned char*)(vector)->buffer)[n]
#define GVECTORNU16(vector, n) ((unsigned short*)(vector)->buffer)[n]
#define GVECTORNU32(vector, n) ((unsigned int*)(vector)->buffer)[n]

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
