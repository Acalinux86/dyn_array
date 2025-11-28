#ifndef DYN_ARRAY_H_
#define DYN_ARRAY_H_

#include <assert.h>
#include <stdlib.h>

#define DYN_ARRAY_INITIAL_CAPACITY 256

// NOTE: New Dynamic Array Initialization
#define array_new(array)                                                \
    do {                                                                \
        (array)->count = 0;                                             \
        (array)->capacity = DYN_ARRAY_INITIAL_CAPACITY;                 \
        (array)->contents = malloc(                                     \
            sizeof(*(array)->contents)*(array)->capacity);              \
        assert((array)->contents != NULL &&                             \
               "Memory Allocation For Dynamic Array Contents Failed");  \
    } while (0)

// NOTE: Remove An Element of Specified Index and Shift the Dynamic Array
#define array_delete_content(array, index)                          \
    do {                                                            \
        /* Assert Dynamic Array count is greater than zero */       \
        assert(index < (array)->count);                             \
        /* Assert pointer to contents is not NULL */                \
        assert((array)->contents != NULL);                          \
        /* Shift the Dynamic Array elements if deleting is occur-
           ing at aspecific index */                                \
        if (index < (array)->count - 1) {                           \
            for (size_t i = index; i < (array)->count - 1; i++) {   \
                (array)->contents[i] = (array)->contents[i + 1];    \
            }                                                       \
        }                                                           \
        /* Decrease Dynamic Array Count */                          \
        (array)->count--;                                           \
    } while (0)

// NOTE: Remove Last Element From Dynamic Array
#define array_pop(array)                                                \
    do {                                                                \
        if ((array)->count == 0) {                                      \
            fprintf(stderr,                                             \
                    "Warning: Attempting to Pop From An empty Dynamic Array.\n"); \
            break;                                                      \
        } else {                                                        \
            array_delete_content((array), (array)->count - 1);          \
        }                                                               \
    } while (0)

// NOTE: Push An Element To A Specified Index in An Dynamic Array
#define array_push(array, content, index)                               \
    do {                                                                \
        /* Check if the array needs resizing*/                          \
        if ((array)->count >= (array)->capacity) {                      \
            (array)->capacity =                                         \
                (array)->capacity == 0 ?                                \
                DYN_ARRAY_INITIAL_CAPACITY :                            \
                (array)->capacity * 2 + 1;                              \
            /* Reallocate the array contents to the new capacity*/      \
            (array)->contents =                                         \
                realloc(                                                \
                    (array)->contents,                                  \
                    sizeof(*(array)->contents)*(array)->capacity        \
                    );                                                  \
            /* Assert The Reallocation pointer is not NULL */           \
            assert((array)->contents != NULL &&                         \
                   "Memory Reallocation For Dynamic Array Failed.");    \
        }                                                               \
        /* Shift the elements if insert is happening at a specific
           index */                                                 \
        if (index != (array)->count) {                              \
            for (size_t i = (array)->count; i > index; --i) {       \
                (array)->contents[i] = (array)->contents[i - 1];    \
            }                                                       \
        }                                                           \
        /* Increase Dynamic Array count and append the content  */  \
        (array)->contents[index] = content;                         \
        (array)->count++;                                           \
    } while (0)

// NOTE: Append An Content in the end
#define array_append(array, content) array_push((array), content, (array)->count)

// NOTE: Destroy the Dynamic Array
#define array_delete(array)                     \
    do {                                        \
        free((array)->contents);                \
        (array)->count = 0;                     \
        (array)->capacity = 0;                  \
        (array)->contents = NULL;               \
    } while(0)

#endif // DYN_ARRAY_H_
