
#include "../include/minitalk_bonus.h"

void	ack_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	server_pid;
	char *str;

	signal(SIGUSR2, ack_handler);
	if (argc != 3 || !all_num(argv[1]))
	{
		ft_printf("Error: wrong arguments.\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error: Invalid PID.\n");
		return (1);
	}
	i = 0;
	str = argv[2];
	while (str[i])
	{
		send_bit(server_pid, str[i]);
		i++;
	}
	send_bit(server_pid, '\0');
	while (1)
		pause();
	return (0);
}
