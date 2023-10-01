# get_next_line
## Overview

This project is part of the curriculum at 42 school and involves the implementation of the `get_next_line` function in the C programming language. The purpose of this function is to read lines from a file descriptor. It is designed to handle single file descriptors in the main version and supports multiple file descriptors in the bonus version.

## Function Description
The `get_next_line` function reads the file descriptor and returns the next line from the file each time it is called. It takes the file descriptor as a parameter and returns a dynamically allocated string containing the line read from the file. The function follows these steps:

- The function uses a static buffer to store data read from the file descriptor.
- It handles different buffer sizes specified by the **BUFFER_SIZE** macro.
- The function appends the buffer contents to the line variable until a newline character is encountered or the end of the file is reached.
- It uses the **ft_strjoin** function to concatenate the buffer contents and the line.
- The **clear_and_check_end** function is used to remove the processed data from the buffer and check if a line has ended.
- The function continues reading from the file descriptor until a complete line is obtained or the end of the file is reached.
- Finally, the function returns a line read from the file descriptor as a dynamically allocated string, or NULL if an error occurs or the end of the file is reached.

### Bonus Version
The bonus version of the `get_next_line` function supports multiple file descriptors. It uses a two-dimensional array of buffers to store data for each file descriptor, allowing simultaneous reading from multiple files.

## Usage
To use this function, you need to follow these steps:

- Include the header file in your source code where you want to use the `get_next_line` function. You can use `#include "get_next_line.h"`.
- Call the `get_next_line` function with the file descriptor as the argument. The function will read the next line from the file and return a pointer to a dynamically allocated string containing the line.
- Check the return value of the `get_next_line` function. If the function successfully reads a line, it returns a pointer to the line. If it reaches the end of the file or encounters an error, it returns NULL.
- After you finish using the line, make sure to free the memory allocated by the `get_next_line` function using the `free()` function.

Here's an example usage of the `get_next_line` function:
  
```c
#include "get_next_line.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY); // Open the file in read-only mode

    if (fd == -1) {
        // Error handling
        return 1;
    }

    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    printf("\n");

    close(fd); // Close the file
    return 0;
}
```
In this example, the `get_next_line` function is called inside a loop until it returns NULL, indicating that the end of the file has been reached. Each line is printed, and the memory allocated for the line is freed before moving on to the next line.

## Contact
For any inquiries or feedback regarding this project, please contact [rpp@ruippeixe.com](mailto:rpp@ruippeixe.com).

Thank you for your interest!
