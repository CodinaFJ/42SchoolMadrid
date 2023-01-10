
#include<unistd.h>

int main(void)
{
	char	c;

	c = 'a';
	//write(1, &c, 1);
	write(1, "hola", 5);
	write(1, "\n", 1);
	return (0);
}
