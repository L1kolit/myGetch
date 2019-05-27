#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <stropts.h>

int _kbhit() {
static const int STDIN = 0;
static bool initialized = false;

if (! initialized) {
    termios term;
    tcgetattr(STDIN, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN, TCSANOW, &term);
    setbuf(stdin, NULL);
    initialized = true;
}

int bytesWaiting;
ioctl(STDIN, FIONREAD, &bytesWaiting);
return bytesWaiting;
}

    using namespace std;

int mygetch() {
struct termios oldt,
newt;
int ch;
tcgetattr( STDIN_FILENO, &oldt );
newt = oldt;
newt.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}