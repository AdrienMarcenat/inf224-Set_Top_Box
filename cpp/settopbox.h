#ifndef SETTOPBOX_H
#define SETTOPBOX_H

#include "tcpserver.h"
#include "database.h"
#include "table.h"

#include <signal.h>
#include <iostream>

class SetTopBox
{
    public:
        SetTopBox();
        int  run();
        void shutdown();
    private:
        TCPServer server;
        DataBase base;
        Table table;
};

#endif // SETTOBOX_H
