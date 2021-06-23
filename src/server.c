#include "../includes/minitalk.h"
#include "../libft/libft.h"

int		ft_pow(int base, int power)
{
	int res;

	if (power == 0)
		return (1);
	res = 1;
	while (power--)
		res *= base;
	return (res);
}

int 	ft_atoi_base_2(char *letter)
{
	int dex;
	int	len;
	int pow;

	pow = 0;
	len = 7;
	dex = 0;
	while (len >= 0)
	{
		dex += (letter[len] - '0') * ft_pow(2, pow);
		len--;
		pow++;
	}
	return (dex);
}

void handler(int num)
{
	char		letter[9];
	static int 	bit;
	char 		symbol;

	if (num == SIGUSR1)
		letter[bit] = '1';
	if (num == SIGUSR2)
		letter[bit] = '0';
	bit++;
	if (bit == 8)
	{
		letter[8] = 0;
		symbol = ft_atoi_base_2(letter);
		if (symbol == '\0')
			write(1, "\n", 1);
		else
			write(1, &symbol, 1);
		bit = 0;
		ft_bzero(letter, 8);
	}
}

int main()
{
	int mypid;
	struct sigaction sact;
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = 0;
	sact.sa_handler = &handler;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);

	mypid = getpid();
	printf( "Client pid=%d started\n", mypid);
	while (1)
		pause();
}

