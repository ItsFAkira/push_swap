

_This project has been made as part of the curriculum of 42 by antonfe2_

# Libft ![42](https://img.shields.io/badge/School-42-black)

# DESCRIPTION
Libft is a custom C library that replicates and extends standard libc functions.

The goal of this project is to reimplement standard C library functions and build a personal reusable library for future projects.

## Structure

```
libft/
├── *.c files
├── libft.h
├── Makefile
```

## Functions
Each function named here contains a description of its use and a `main()` to test it out.

### 📑ft_atoi
_Converts a string to an integer._

```c
int	main(void)
{
	#include <stdio.h>

	printf("%d\n", ft_atoi("42"));
	return (0);
}
```

### 📑ft_bzero
_Sets a block of memory to zero._
```c
int	main(void)
{
	#include <stdio.h>

	char str[10] = "hello";

	ft_bzero(str, 5);
	printf("%s\n", str);
}
```
### 📑ft_calloc
_Allocates memory for an array and initializes it to zero. Caller has to free memory._
```c
int	main(void)
{
	#include <stdio.h>

	int *arr;
	int i;

	i = 0;
	arr = (int *)ft_calloc(5, sizeof(int));
	while (i < 5)
	{
		arr[i] = 'a';
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);
}
```
### 📑ft_isalnum
_Checks if a character is alphanumeric._
```c
int	main(void)
{
	#include <stdio.h>

	printf("A: %d\n", ft_isalnum('A'));
	printf("z: %d\n", ft_isalnum('z'));
	printf("5: %d\n", ft_isalnum('5'));
	printf("?: %d\n", ft_isalnum('?'));
	printf("Space: %d\n", ft_isalnum(' '));
}
```
### 📑ft_isalpha
_Checks if a character is an alphabetic letter._
```c
int	main(void)
{
	#include <stdio.h>

	printf("%d\n", ft_isalpha('A'));
	printf("%d\n", ft_isalpha('z'));
	printf("%d\n", ft_isalpha('1'));
}
```
### 📑ft_isascii
_Checks if a character is part of the ASCII set (0–127)._
```c
int	main(void)
{
	#include <stdio.h>

	printf("%d\n", ft_isascii(65));
	printf("%d\n", ft_isascii(200));
}
```
### 📑ft_isdigit
_Checks if a character is a decimal digit (0–9)._
```c
int	main(void)
{
	#include <stdio.h>

	printf("%d\n", ft_isdigit('5'));
	printf("%d\n", ft_isdigit('a'));
}
```
### 📑ft_isprint
_Checks if a character is printable, including space._
```c
int	main(void)
{
	#include <stdio.h>

	printf("%d\n", ft_isprint('A'));
	printf("%d\n", ft_isprint(31));
}
```
### 📑ft_itoa
_Converts an integer to a string. Caller has to free memory._
```c
int	main(void)
{
	#include <stdio.h>

	char *str;

	str = ft_itoa(42);
	printf("%s\n", str);
	free(str);
}
```
### 📑ft_memchr
_Searches for a character in a block of memory._
```c
int	main(void)
{
	#include <stdio.h>

	char str[] = "hello";
	char *res;

	res = ft_memchr(str, 'e', 5);
	printf("%s\n", res);
}
```
### 📑ft_memcmp
_Compares two blocks of memory._
```c
int	main(void)
{
	#include <stdio.h>

	char a[] = "abc";
	char b[] = "abd";

	printf("%d\n", ft_memcmp(a, b, 3));
}
```
### 📑ft_memcpy
_Copies memory from source to destination._
```c
int	main(void)
{
	#include <stdio.h>

	char src[] = "hello";
	char dst[10];

	ft_memcpy(dst, src, 6);
	printf("%s\n", dst);
}
```
### 📑ft_memmove
_Copies memory safely, handling overlapping regions._
```c
int	main(void)
{
	#include <stdio.h>

	char str[] = "abcdef";

	ft_memmove(str + 2, str, 4);
	printf("%s\n", str);
}
```
### 📑ft_memset
_Fills a block of memory with a constant byte._
```c
int	main(void)
{
	#include <stdio.h>

	char str[10];

	ft_memset(str, 'A', 5);
	printf("%s\n", str);
}
```
### 📑ft_putchar_fd
_Outputs a character to a given file descriptor._
```c
int	main(void)
{
	#include <stdio.h>

	ft_putchar_fd('A', 1);
}
```
### 📑ft_putendl_fd
_Outputs a string to a given file descriptor followed by a newline._
```c
int	main(void)
{
	#include <stdio.h>

	ft_putendl_fd("Hello", 1);
}
```
### 📑ft_putnbr_fd
_Outputs an integer to a given file descriptor._
```c
int	main(void)
{
	#include <stdio.h>

	ft_putnbr_fd(42, 1);
}
```
### 📑ft_putstr_fd
_Outputs a string to a given file descriptor._
```c
int	main(void)
{
	#include <stdio.h>

	ft_putstr_fd("Hello", 1);
}
```
### 📑ft_split
_Splits a string into an array of strings using a delimiter. Caller has to free memory._
```c
int	main(void)
{
#include <stdio.h>

	char **arr;
	int i;

	arr = ft_split("hello world test", ' ');
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}
```
### 📑ft_strchr
_Searches for the first occurrence of a character in a string._
```c
int	main(void)
{
	#include <stdio.h>

	char str[] = "hello world";

	printf("%s\n", ft_strchr(str, 'o'));
}
```
### 📑ft_strdup
_Duplicates a string by allocating new memory. Caller has to free memory._
```c
int	main(void)
{
	#include <stdio.h>
	char *str;

	str = ft_strdup("hello");
	printf("%s\n", str);
	free(str);
}
```
### 📑ft_striteri
_Applies a function to each character of a string, passing its index. This example also adds an extra function to make it work._
```c
void to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	#include <stdio.h>

	char str[] = "hello";

	ft_striteri(str, to_upper);
	printf("%s\n", str);
}
```
### 📑ft_strjoin
_Concatenates two strings into a new allocated string. Caller has to free memory._
```c
int	main(void)
{
	#include <stdio.h>

	char *str;

	str = ft_strjoin("hello ", "world");
	printf("%s\n", str);
	free(str);
}
```
### 📑ft_strlcat
_Appends a string to another with size limitation, ensuring null termination._
```c
int	main(void)
{
	#include <stdio.h>

	char dst[20] = "hello ";
	char src[] = "world";

	ft_strlcat(dst, src, 20);
	printf("%s\n", dst);
}
```
### 📑ft_strlcpy
_Copies a string into a buffer with size limitation and null termination._
```c
int	main(void)
{
	#include <stdio.h>

	char src[] = "hello";
	char dst[10];

	ft_strlcpy(dst, src, 10);
	printf("%s\n", dst);
}
```
### 📑ft_strlen
_Returns the length of a string._
```c
int	main(void)
{
	#include <stdio.h>

	printf("%zu\n", ft_strlen("hello"));
}
```
### 📑ft_strmapi
_Applies a function to each character of a string and returns a new string. This example also adds an extra function to make it work. Caller has to free memory._
```c
char to_upper_i(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	#include <stdio.h>

	char *str;

	str = ft_strmapi("hello", to_upper_i);
	printf("%s\n", str);
	free(str);
}
```
### 📑ft_strncmp
_Compares two strings up to a given number of characters._
```c
int	main(void)
{
	#include <stdio.h>

	printf("%d\n", ft_strncmp("hello", "hella", 5));
}
```
### 📑ft_strnstr
_Searches for a substring within a string up to a given length._
```c
int	main(void)
{
	#include <stdio.h>

	char str[] = "hello world";

	printf("%s\n", ft_strnstr(str, "world", 11));
}
```
### 📑ft_strrchr
_Searches for the last occurrence of a character in a string._
```c
int	main(void)
{
	#include <stdio.h>

	char str[] = "hello world";

	printf("%s\n", ft_strrchr(str, 'o'));
}
```
### 📑ft_strtrim
_Removes all leading and trailing characters found in a set from a string. Caller has to free memory._
```c
int	main(void)
{
	#include <stdio.h>

	char *str;

	str = ft_strtrim("  hello  ", " ");
	printf("%s\n", str);
	free(str);
}
```
### 📑ft_substr
_Extracts a substring from a string. Caller has to free memory._
```c
int	main(void)
{
	#include <stdio.h>

	char *str;

	str = ft_substr("hello world", 6, 5);
	printf("%s\n", str);
	free(str);
}
```
### 📑ft_tolower
_Converts an uppercase letter to lowercase._
```c
int	main(void)
{
	#include <stdio.h>

	printf("%c\n", ft_tolower('A'));
}
```
### 📑ft_toupper
_Converts a lowercase letter to uppercase._
```c
int	main(void)
{
	#include <stdio.h>

	printf("%c\n", ft_toupper('a'));
}
```
### 📑ft_lstadd_back
_Adds a new node at the end of a linked list._
```c
int	main(void)
{
	#include <stdio.h>

	t_list *list;
	t_list *node;

	list = ft_lstnew("first");
	node = ft_lstnew("second");

	ft_lstadd_back(&list, node);
	printf("%s\n", (char *)list->next->content);
}
```
### 📑ft_lstadd_front
_Adds a new node at the beginning of a linked list._
```c
int	main(void)
{
	#include <stdio.h>

	t_list *list;
	t_list *node;

	list = ft_lstnew("second");
	node = ft_lstnew("first");

	ft_lstadd_front(&list, node);
	printf("%s\n", (char *)list->content);
}
```
### 📑ft_lstclear
_Deletes and frees all nodes of a linked list. This example also adds an extra function to make it work._
```c
void del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *list;

	list = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));

	ft_lstclear(&list, del);
}
```
### 📑ft_lstdelone
_Deletes a single node of a linked list and frees its content. This example also adds an extra function to make it work._
```c
void del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *node;

	node = ft_lstnew(ft_strdup("hello"));
	ft_lstdelone(node, del);
}
```
### 📑ft_lstiter
_Applies a function to the content of each node in a linked list. This example also adds an extra function to make it work._
```c
#include <stdio.h>

void print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list *list;

	list = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));

	ft_lstiter(list, print_content);
}
```
### 📑ft_lstlast
_Returns the last node of a linked list._
```c
int	main(void)
{
	#include <stdio.h>

	t_list *list;
	t_list *last;

	list = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("last")));

	last = ft_lstlast(list);
	printf("%s\n", (char *)last->content);
}
```
### 📑ft_lstmap
_Applies a function to each node’s content and creates a new linked list with the results. This example also adds two extra functions to make it work._
```c
void	*dup_content(void *content)
{
	return (ft_strdup((char *)content));
}

void	del(void *content)
{
	free(content);
}

void	clear_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

int	main(void)
{
	t_list *list;
	t_list *new;

	ft_lstadd_back(&list, ft_lstnew(ft_strdup("hello")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));

	new = ft_lstmap(list, dup_content, del);
	clear_list(&list);
	clear_list(&new);
}
```
### 📑ft_lstnew
_Creates a new linked list node. Caller has to free memory._
```c
int	main(void)
{
	#include <stdio.h>

	t_list *node;

	node = ft_lstnew(ft_strdup("hello"));
	printf("%s\n", (char *)node->content);
	free(node->content);
	free(node);
}
```
### 📑ft_lstsize
_Returns the number of nodes in a linked list._
```c
int	main(void)
{
	#include <stdio.h>

	t_list *list;
	t_list	*tmp;

	list = ft_lstnew(ft_strdup("one"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("two")));
	printf("%d\n", ft_lstsize(list));

	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}
```
# INSTRUCTIONS

## Usage
Add `#include "libft.h"` in any C file to be able to use the library.

## Compilation

`make all` compiles library.

`make clean` deletes .o files.

`make fclean` deletes .o files and libft.a.

`make re` recompiles everything.

`make test` prints in console main.c file.

To be able to test the function, create a `main.c` file in the root directory. Inside, add any `int main(void)` function showed above.

# RESOURCES

- Linux man-pages
- POSIX specification
- cppreference.com
- The C Programming Language (K&R)
- C Programming: A Modern Approach
- Valgrind
- GDB
- Reddit
- Github

## USE OF AI

In this project AI has been used as a tool to help the author understand how the functions works and how to use them. AI has been used too to help the author make the README.md

# ft_printf ![42](https://img.shields.io/badge/School-42-black)

# DESCRIPTION

`ft_printf` is a project from the :contentReference[oaicite:0]{index=0} curriculum whose goal is to recreate the behavior of the standard C `printf` function.

The project focuses on:
- Variadic functions
- String formatting
- Base conversions
- Memory management
- Low-level output handling using `write`

This implementation supports the most common conversion specifiers and mimics the behavior of the original `printf`.

## Supported conversions

| Specifier | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

---

## Function Prototype

```c
int	ft_printf(const char *format, ...);
```


## Return Value

`ft_printf` returns:
- The total number of printed characters
- `-1` if an error occurs


# INSTRUCTIONS

## Usage
Add `#include "ft_printf.h"` in any C file to be able to use the library.

## Compilation

`make all` compiles library.

`make clean` deletes .o files.

`make fclean` deletes .o files and libft.a.

`make re` recompiles everything.

`make test` prints in console main.c file.

To be able to test the function, create a `main.c` file in the root directory. You can use this code to test all the functions at the same time:
```c
#include "ft_printf.h"

int	main(void)
{
	int		r1;
	int		r2;
	char	*null;

	null = NULL;
	//Test %c
	printf("=== TEST 1: %%c ===\n");
	r1 = printf("printf:    [%c]\n", 'A');
	r2 = ft_printf("ft_printf: [%c]\n", 'A');
	printf("printf return:    %d\n", r1);
	printf("ft_printf return: %d\n\n", r2);

	//Test %%
	printf("=== TEST 2: %%%% ===\n");
	r1 = printf("printf:    [%%]\n");
	r2 = ft_printf("ft_printf: [%%]\n");
	printf("printf return:    %d\n", r1);
	printf("ft_printf return: %d\n\n", r2);

	//Test %s
	printf("=== TEST 3: %%s ===\n");
	r1 = printf("printf:    [%s]\n", "Hola");
	r2 = ft_printf("ft_printf: [%s]\n", "Hola");
	printf("printf:    [%s]\n", null);
	ft_printf("ft_printf: [%s]\n", null);
	printf("printf return:    %d\n", r1);
	printf("ft_printf return: %d\n\n", r2);

	//Test %p
	printf("=== TEST 4: %%p ===\n");
	r1 = printf("printf:    [%p]\n", (void *)&r1);
	ft_printf("ft_printf: [%p]\n", (void *)&r1);
	printf("printf:    [%p]\n", NULL);
	ft_printf("ft_printf: [%p]\n\n", NULL);

	//Test %d %i
	printf("=== TEST 5: %%d %%i ===\n");
	r1 = printf("printf:    [%d]\n", -2147483647);
	r2 = ft_printf("ft_printf: [%d]\n", -2147483647);
	printf("printf return:    %d\n", r1);
	printf("ft_printf return: %d\n\n", r2);

	//Test %u
	printf("=== TEST 6: %%u ===\n");
	r1 = printf("printf:    [%u]\n", -2147483647);
	r2 = ft_printf("ft_printf: [%u]\n", -2147483647);
	printf("printf return:    %d\n", r1);
	printf("ft_printf return: %d\n\n", r2);

	//Test %X
	printf("=== TEST 7: %%X ===\n");
	r1 = printf("printf:    [%X]\n", -2147483647);
	r2 = ft_printf("ft_printf: [%X]\n", -2147483647);
	printf("printf:    [%X]\n", -9999999);
	ft_printf("ft_printf: [%X]\n", -9999999);
	printf("printf return:    %d\n", r1);
	printf("ft_printf return: %d\n\n", r2);

	//Test %x
	printf("=== TEST 8: %%x ===\n");
	r1 = printf("printf:    [%x]\n", -2147483647);
	r2 = ft_printf("ft_printf: [%x]\n", -2147483647);
	printf("printf:    [%x]\n", -9999999);
	ft_printf("ft_printf: [%x]\n", -9999999);
	printf("printf return:    %d\n", r1);
	printf("ft_printf return: %d\n\n", r2);
}
```