#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char	test[5 + 1];

	fd = open(argv[1], O_RDONLY);
	printf("Valeur de fd: %d\n", fd);
	while (fd)
	{
		ret = read(fd,test, 5);
		test[ret] = '\0';
		printf("%s\n", test);
		if (ret == 0)
			fd = 0;;
	}
	return (0);
}