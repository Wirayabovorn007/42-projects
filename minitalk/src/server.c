
#include "../include/minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;
	struct sigaction sa;

	if (argc != 1 || !argv[0])
		return (1);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_handler = bit_to_str;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
