#include "shell.h"
/**
* _printint - prints decimals
* @error: counter passed from main
* Return: number of numbers printed
*/
int _printint(int error)
{
	int num, last = error % 10, digit, num2 = 1;

	error = error / 10;
	num = error;
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			num2 = num2 * 10;
			num = num / 10;
		}
		num = error;
		while (num2 > 0)
		{
			digit = num / num2;
			_putchar(digit + '0');
			num = num - (digit * num2);
			num2 = num2 / 10;
		}
	}
	_putchar(last + '0');
	return (error);
}
