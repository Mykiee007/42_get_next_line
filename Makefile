*This project has been created as part of the 42 curriculum by mvelasqu*

# get_next_line

A function that reads a line from a file descriptor, one line at a time.

## Description

`get_next_line()` returns a line ending with a newline character (`\n`) from a file descriptor.
If there is nothing left to read, it returns `NULL`.

## INSTRUCTIONS


### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
### Usage

```c
char *get_next_line(int fd);
```

### Main Test

Requires four (4) .txt files to test. 

```bash
// This main is for testing only, it is not included in the files to be submitted.
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd[4];
	char	*line;
	int		choice;
	int		i;

	if (argc != 5)
	{
		printf("Usage: %s file1 file2 file3 file4\n", argv[0]);
		return (1);
	}

	i = 0;
	while (i < 4)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		if (fd[i] < 0)
		{
			printf("open");
			return (1);
		}
		i++;
	}

	printf("\nFiles opened:\n");
	printf("1 → %s\n", argv[1]);
	printf("2 → %s\n", argv[2]);
	printf("3 → %s\n", argv[3]);
	printf("4 → %s\n\n", argv[4]);

	while (1)
	{
		printf("CHOOSE fd (1-4) OR 0 TO EXIT: ");
		if (scanf("%d", &choice) != 1)
			break;
		if (choice == 0)
			break;
		if (choice < 1 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		line = get_next_line(fd[choice - 1]);
		if (!line)
		{
			printf("[EOF on fd %d]\n", choice);
			continue;
		}

		printf("fd %d: \n%s\n", choice, line);
		free(line);
	}

	i = 0;
	while (i < 4)
	{
		close(fd[i]);
		i++;
	}

	return (0);
}
```

### Return Value
- A line read from the file descriptor
- NULL if EOF is reached r an error occurs

### NOTES
- Handles multiple file descriptors
- Uses a static buffer

## RESOURCES
 
- Readme.md - [makeareadme.com](https://www.makeareadme.com/), [geeksforgeeks.org](https://www.geeksforgeeks.org/git/what-is-readme-md-file/);

