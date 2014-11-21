#include <iostream>
#include <csignal>
#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#define sleep(n) Sleep(1000 * (n))
#else
#include <unistd.h>
#endif

using namespace std;

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received." << endl;
    // cleanup and close up stuff here
    // terminate program
    exit(signum);
}

int main()
{
    // register signal SIGINT and signal handler
    signal(SIGINT, signalHandler);

    while(1)
    {
        cout << "Going to sleep..." << endl;
        sleep(1);
    }

    return 0;
}
