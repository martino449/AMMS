#ifndef AMMS_H  // Include guard to prevent multiple inclusions
#define AMMS_H

#include <stddef.h>  // For size_t
#include <stdio.h>   // For printf and stderr

// Structure definition for ManagedObject
typedef struct {
    void* data;                  // Pointer to the actual data
    size_t size;                // Size of the data
    int mutable_borrowed;       // 1 = mutably borrowed, 0 = not borrowed mutably
    int immutable_borrow_count;  // Tracks the number of active immutable borrows
    int ref_count;              // Reference count for automatic memory management
} ManagedObject;

// Function prototypes
ManagedObject* create_object(size_t size);
void add_reference(ManagedObject* obj);
void remove_reference(ManagedObject* obj);
void* borrow_immutable(ManagedObject* obj);
void* borrow_mutable(ManagedObject* obj);
void return_object(ManagedObject* obj);
void destroy_object(ManagedObject* obj);
void print_object_status(ManagedObject* obj);
int is_mutably_borrowed(ManagedObject* obj);
int is_immutably_borrowed(ManagedObject* obj);

#endif // AMMS_H
