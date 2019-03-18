#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	char	*line;
	char	*file;
	int		fd;
	int		ret;
	int		i;

	i = 1;
	while (i < argc)
	{
		file = argv[i];
		fd = open(file, O_RDONLY);
		ret = 1;
		while (ret)
		{
			ret = get_next_line(fd, &line);
			if (ret == -1)
			{
				printf("ERROR (get_next_line returned -1)\n");
				return (0);
			}
			else if (ret == 0)
			{
				if (line != NULL)
					free(line);
				break ;
			}
			printf("%s", line);
			free(line);
			if (ret == 1)
				printf("\n");
		}
		i++;
	}
	i = 0;
	/*
	while (i < argc)
	{
		close(fd);
		*/
	return (0);
}
