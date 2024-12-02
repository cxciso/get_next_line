#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main (void)
{
   int fd; 
   fd = open("text",O_RDONLY);
	char *str;
	str =get_next_line(fd);
	while (str)
	 {
		printf("%s", str);
		str =get_next_line(fd);
	 }
}
