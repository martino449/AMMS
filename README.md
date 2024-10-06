# Advanced Memory Management System (AMMS)

**AMMS** is a simplified memory management system implemented in C, inspired by the borrow checker principles of Rust. It provides an intuitive way to handle mutable and immutable borrows of objects, ensuring safe memory access and automatic memory management through reference counting.

## Features

- **Automatic Memory Management**: Utilizes reference counting to manage the lifecycle of objects automatically, preventing memory leaks.
- **Borrowing Mechanism**: Supports both mutable and immutable borrows, allowing safe concurrent access to objects while enforcing strict borrowing rules.
- **Error Handling**: Built-in checks prevent invalid memory access, providing error messages when borrowing conditions are not met.
- **Debugging Support**: Includes functions to print the status of managed objects, facilitating easier debugging and tracking of reference counts and borrow states.

## Core Functions

- `create_object(size_t size)`: Create a new managed object with the specified size.
- `borrow_immutable(ManagedObject* obj)`: Borrow an object immutably (read-only access).
- `borrow_mutable(ManagedObject* obj)`: Borrow an object mutably (read and write access).
- `return_object(ManagedObject* obj)`: Return the borrowed object, updating reference counts and frees it if the references reach 0.
- `destroy_object(ManagedObject* obj)`: Clean up and free the object's memory when it is no longer needed.

## Example Usage

```c
#include "amms.h"

int main() {
    // Create a new managed object
    ManagedObject* obj = create_object(256);
    
    // Borrow the object mutably and modify data
    char* data = (char*)borrow_mutable(obj);
    strcpy(data, "Hello, AMMS!");
    return_object(obj);

    // Borrow the object immutably and read data
    char* read_data = (char*)borrow_immutable(obj);
    printf("Data: %s\n", read_data);
    return_object(obj);

    // Destroy the object when done
    return_object(obj);

    return 0;
}
```

## Getting Started

To use AMMS in your project, simply include the header file and link against the provided implementation. Detailed usage examples can be found in the [Documentation](https://github.com/martino449/AMMS/blob/main/Getting_Started.md).

## License

This project is licensed under the [MIT License](https://github.com/martino449/AMMS/blob/main/LICENSE).
