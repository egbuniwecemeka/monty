#include "monty.h"

/**
 * open_file - opeans a file
 * @file_name: files path
 *
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads a file
 * @fd: pointer to file des
 *
 * Return: void
 */
void read_file(FILE *fd)
{
	int num_line, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (num_line = 1; getline(&buffer, &len, fd) != -1; num_line++)
	{
		format = parse_line(buffer, num_line, format);
	}

	free(buffer);
}
