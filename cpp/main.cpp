#include <iostream>
#include <signal.h>

#include "settopbox.h"

SetTopBox box;

void signalHandler(int signal)
{
   std::cout << "\n Interrupt signal (" << signal << ") received.\n";
   box.shutdown();
   
   exit(signal);
}

int main(int argc, char* argv[])
{
    signal(SIGINT, signalHandler);

    return box.run();
}

