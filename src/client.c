#include <stdlib.h>
#include <signal.h>
#include "../includes/minitalk.h"
#include "../libft/libft.h"

void word_sender(char *word, char *pid)
{
	char	letter;
	int		bytes;
	int		len;

	len = ft_strlen(word) + 1;
	while (len--)
	{
		bytes = 0;
		letter = *word;
		while (bytes < 8)
		{
			if ((letter & 10000000) == 10000000)
				kill(ft_atoi(pid), SIGUSR1);
			else
				kill(ft_atoi(pid), SIGUSR2);
			letter = letter << 1;
			usleep(150);
			bytes++;
		}
		word++;
	}
}

int main(int argc, char **argv)
{
	int		index;

	if (argc < 3)
		return (-1);
	index = 2;
	while(argv[index])
	{
		word_sender(argv[index], argv[1]);
		index++;
	}
	return (0);
}

