#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*return number of words in a string depends on a seperateur*/
static int	count_words(char const *str, char sep)
{
	int	wrdcount;
	int	i;

	if (!str)
		return (0);
	wrdcount = 0;
	i = 0;
	while (str[i] == sep)
		i++;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			wrdcount++;
		i++;
	}
	return (wrdcount);
}

/*return the size of the next word of a string depends on a seperateur*/
static int	word_size(char const *str, char sep)
{
	int	i;
	int	word_size;

	if (!str)
		return (0);
	i = 0;
	word_size = 0;
	while (*str == sep)
		str++;
	while (str[i] && str[i] != sep)
	{
		word_size++;
		i++;
	}
	return (word_size);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		number_of_words;
	int		i;

	i = 0;
	number_of_words = count_words(s, c);
	matrix = (char **)malloc(sizeof(char *) * (number_of_words + 1));
	if (!matrix || !s)
		return (NULL);
	while (*s && i < number_of_words)
	{
		while (*s && *s == c)
			s++;
		matrix[i] = (char *)malloc(sizeof(char) * word_size(s, c) + 1);
		if (!matrix[i])
		{
			// ft_freematrix(matrix);
			return (NULL);
		}
		strlcpy(matrix[i++], s, word_size(s, c) + 1);
		s = s + word_size(s, c);
	}
	matrix[i] = NULL;
	return (matrix);
}

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void	print_matrix(char **matrix)
{
	int	i = 0;
	int j;

	ft_putchar_fd('{', 1);
	while (matrix[i])
	{
		j = 0;
		ft_putchar_fd('[', 1);
		while (matrix[i][j])
		{
			ft_putchar_fd(matrix[i][j], 1);
			j++;
		}
		ft_putchar_fd(']', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('}', 1);
}

int main(int argc, char **argva, char **env)
{
    char *str = "/bin/ls -la";
    char **argv;
    argv = ft_split(str, ' ');
    

    // while (*env)
    // {
    //     printf("%s\n", *env);
    //     env++;
    // }
    print_matrix(argv);
    printf(" %s\n\n", "ffffffffffffffffffffff");
    execve(argv[0], argv, NULL);
    fprintf(stderr,"%s\n\n", "ff22222222222222222fff");
    return (0);
}
