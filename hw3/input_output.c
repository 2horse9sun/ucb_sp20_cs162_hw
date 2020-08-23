#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	char str[999];
	gets(str);
	printf("pipe:%s\n", str);
	return 0;
}