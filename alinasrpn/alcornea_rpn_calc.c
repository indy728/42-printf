nclude <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256
#define binop(x) b = pop(), a = pop(), push(x)
int stack[MAX];
int top;

void push(int item)
{
	if (top >= MAX)
	{
		printf("Error\n");
		exit(1);
	}
	stack[top++] = item;
}

int pop()
{
	if (!top)
	{
		printf("Error\n");
		exit(1);
	}
	return (stack[--top]);
}

char *ft_strtok(char *str, char *delim)
{
	static int pos;
	static char *s;
	int i;
	int j;
	int start;

	i = 0;
	j = 0;
	start = pos;
	if (str != NULL)
		s = str;
	while (s[pos] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (s[pos] == delim[j])
			{
				s[pos] = '\0';
				pos = pos + 1;
				if (s[start] != '\0')
					return (&s[start]);
				else
				{
					start = pos;
					pos--;
					break;
				}
			}
			j++;
		}
		pos++;
	}
	s[pos] = '\0';
	if (s[start] == '\0')
		return (NULL);
	else
		return (&s[start]);
}

int rpn(char *s)
{
	int a;
	int b;
	char *w = " \t\n\r\f";

	s = ft_strtok(s, w);
	while (s)
	{
		a = atoi(s);
		if (a)
			push(a);
		else if (*s == '+')
			binop(a + b);
		else if (*s == '-')
			binop(a - b);
		else if (*s == '*')
			binop(a * b);
		else if (*s == '/')
			binop(a / b);
		else if (*s == '%')
			binop(a % b);
		else
		{
			printf("Error\n");
			exit(1);
		}
		s = ft_strtok(0, w);
	}
	if (top != 1)
	{
		printf("Error\n");
		exit(1);
	}
	return (pop());
}

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", rpn(argv[1]));
	else
		printf("Error\n");
	return (0);
}
