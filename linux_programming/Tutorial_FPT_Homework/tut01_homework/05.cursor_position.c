/* https://thoughtsordiscoveries.wordpress.com/2017/04/26/set-and-read-cursor-position-in-terminal-windows-and-linux/ */
#include <stdio.h>
void SetCursorPosition(int XPos, int YPos) 
{
	printf("\033[%d;%dH",YPos+1,XPos+1);
}

void getCursor(int* x, int* y) 
{
	printf("\033[6n");  /* This escape sequence !writes! the current
                          coordinates to the terminal.
                          We then have to read it from there, see [4,5].
                          Needs <termios.h>,<unistd.h> and some others */
	scanf("\033[%d;%dR", x, y);
}

int main(int argc, char const *argv[])
{
	int x =0, y = 0;
	getCursor(&x, &y);
	printf("Position: %d-%d\n", x, y);
	return 0;
}
