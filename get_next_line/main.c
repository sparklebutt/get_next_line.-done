#include "get_next_line.h"
void only_one_fd()
{
	char *test;
	int x;
	int fd;

	fd = open("empty.txt", O_RDONLY);
	x = 0;
	printf("===empty file===\n");
	while ((test = get_next_line(fd)) != NULL)
	{
		x++;
		printf("EXIT%d----#%s#----", x, test);
		//free(test);
	}
	close(fd);
	fd = open("1char.txt", O_RDONLY);
	x = 0;
	printf("===1char file===\n");
	while ((test = get_next_line(fd)) != NULL)
	{
		x++;
		printf("EXIT%d----#%s#----", x, test);
		free(test);
	}
	close(fd);
	printf("===simple file with a few nl file===\n");
	x = 0;
	fd = open("testies.txt", O_RDONLY);
	while ((test = get_next_line(fd)) != NULL)
	{
		x++;
		printf("EXIT%d----#%s#----", x, test);
		free(test);
	}
	close(fd);
	x = 0;
	fd = open("test.txt", O_RDONLY);
	while ((test = get_next_line(fd)) != NULL)
	{
		x++;
		printf("EXIT%d----#%s#----", x, test);
		free(test);
	}
	close(fd);	
/*	printf("===bit bigger file===\n");
	x = 0;
	fd = open("big.txt", O_RDONLY);
	while ((test = get_next_line(fd)) != NULL)
	{
		x++;
		printf("EXIT%d----#%s#----", x, test);
		//printf("checkcheck\n");
		free(test);
	}
	close(fd);
	x = 0;
	fd = open("bigger.c", O_RDONLY);
	printf("===big cats also a c file===\n");
	while ((test = get_next_line(fd)) != NULL)
	{
		x++;
		printf("EXIT%d----#%s#----", x, test);
		free(test);
	}
	close(fd);*/

}

void simple()
{
	char *test;
	int fd;
	int fd1;
	int x;

	printf("\nsimple 2 fd's test\n");
	x = 0;
	fd = open("1char1.txt", O_RDONLY);
	fd1 = open("1char2.txt", O_RDONLY);
	while (x < 20)
	{
		x++;
		printf("\nx = %d\n", x);
		test = get_next_line(fd);
		printf("*EXIT%d----*%s*-", x, test);
		free(test);
		test = get_next_line(fd1);
		printf("#EXIT%d----#%s#-", x, test);
		free(test);
	}
	close(fd);
	close(fd1);
}

void singles()
{
	char *test;
	int fd;
	int fd1;
	int fd2;
	int fd3;
	int x;

	printf("\nsingles test\n");
	x = 0;
	fd = open("achar.txt", O_RDONLY);
	fd1 = open("bchar.txt", O_RDONLY);
	fd2 = open("cchar.txt", O_RDONLY);
	fd3 = open("dchar.txt", O_RDONLY);
	while (x < 4)
	{
		test = get_next_line(fd);
		printf("*EXIT%d----*%s*-", x, test);
		free(test);
		x++;
		test = get_next_line(fd1);
		printf("*EXIT%d----*%s*-", x, test);
		free(test);
		x++;
		test = get_next_line(fd2);
		printf("*EXIT%d----*%s*-", x, test);
		free(test);
		x++;
		test = get_next_line(fd3);
		printf("*EXIT%d----*%s*-", x, test);
		free(test);
		x++;
	}
	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
}
void rando()
{
	int	fd;
	int	fd1;
	int nofd;
	int	x;
	char *test;

	x = 0;
	fd = open("testies.txt", O_RDONLY);
	fd1 = open("empty.txt", O_RDONLY);
	nofd = -1;
	while (x < 7)
	{
//		printf("===simple file with a few nl file===\n");
//		test = get_next_line(fd);
//		printf("EXIT%d----#%s#-\n", x, test);
//		x++;
//		free(test);
		printf("===empty file===\n");
		test = get_next_line(fd1);
		printf("EXITempty%d----#%s#-\n", x, test);
		//x++;
		//free(test);
		printf("===no fd===\n");
//		printf("nofd = %d\n", nofd);
		test = get_next_line(nofd);

		printf("EXITnofd%d----#%s#-\n", x, test);
		//x++;
		//free(test);

	}
	close(fd);
	close(fd1);
}

int main()
{
	//int fd;
	//char *test;

	//fd = 0;
	//fd = open("empty.txt", O_RDONLY);
	//fd = open("testies.txt", O_RDONLY);
	//fd1 = open("big.txt", O_RDONLY);
	//fd = '0'; //returns null ?
	//fd = open("1char1.txt", O_RDONLY);
	//fd1 = open("1char2.txt", O_RDONLY);
	//fd = open("empty.txt", O_RDONLY);
	printf("MAIN\n");
	only_one_fd();
	//simple();
	//singles();
	//rando();
/*	while ((test = get_next_line(fd)) != NULL)
	{
		x++;
		printf("111EXIT%d----#%s#----", x, test);//get_next_line(fd));
		free(test);
	}
	close(fd);*/
	return(0);

}
