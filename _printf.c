#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

/**
  * _printf - Produce output according to a format
  * @format: String argument
  * @...: Rest of the arguments
  * Return: Return number of characters printed
  */

int _printf(const char *format, ...)
{
	int c_count;
	va_list args;
	char c_value;
	char *s_value;
	int i;

	c_count = strlen(format);
	/* Make args point to the first unnamed value */
	va_start(args, format);

	for (i = 0; i < c_count; i++)
	{
		if (format[i] == '%')
		{
			format++;

			if (format[i] == 'c')
			{
				c_value = (char) va_arg(args, int);
				write(1, &c_value, 1);
				write(1, "\n", 1);
			}
			else if (format[i] == 's')
			{
				s_value = va_arg(args, char*);
				write(1, s_value, strlen(s_value));
				write(1, "\n", 1);
			}
			else if (format[i] == '%')
			{
				write(1, format, 1);
				write(1, "\n", 1);
			}
		}
	}

	va_end(args);
	return (c_count);
}
