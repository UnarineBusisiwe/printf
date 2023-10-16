#include "main.h"

void print_buffer(char *buffer, int *index);

/**
 * _printf - printf function
 * @format: format specifiers
 * Return: printed characters
 */

int _printf(const char *format, ...)
{
	int e, printed = 0, printed_characters = 0;
	int precision, width, size, flags, buffer_index = 0;
	va_list args;

	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (e = 0; format && format[e] != '\0'; i++)
	{
		if (format[e] != '%')
		{
			buffer[buffer_index++] = format[e];

			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			printed_characters++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &e);
			width = get_width(format, &e, args);
			precision = get_precision(format, &e, args);
			size = get_size(format, &e);
			++i;
			printed = handle_print(format, &e, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_characters += printed;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(args);
	return (printed_characters);
}

/**
 * print_buffer - print the characters in the buffer
 * @buffer: Arary of chars
 * @index: index of the characters
 */

void print_buffer(char *buffer, int *index)
{
	if (*index > 0)
		write(1, buffer, *index);
	*index = 0;
}
