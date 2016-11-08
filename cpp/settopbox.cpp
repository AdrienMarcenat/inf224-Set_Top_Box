#include "settopbox.h"

SetTopBox::SetTopBox()
    : server()
    , base()
    , table()
{
    // Fills the data base with some data
    Mulptr photo = table.createPhoto("miroir", 12, 15);
    std::stringstream stream("1;2;Bob;C:/;");
    *photo >> stream;
    Mulptr video = table.createVideo("live", 120);
    //video->unserialize(stream);
    float* batman = new float[2];
    batman[0] = 5;
    batman[1] = 4;
    Mulptr film = table.createFilm("batman", batman, 2);
    //film->unserialize(stream);

    //Register the data base's lambda functions
    base.registerCommand("display",
            [this](Name name, std::ostream& stream)
            {
                table.find(name, stream);
            });

    base.registerCommand("play",
            [this](Name name, std::ostream& stream)
            {
                table.play(name);
            });

    // Set the command calls when the server receive a request
    server.setCallback(base, &DataBase::processRequest);
}

int SetTopBox::run()
{
    // Launch the server
    std::cout << "Starting Server on port " << PORT << std::endl;
    int status = server.run(PORT);

    if (status < 0) 
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}

void SetTopBox::shutdown()
{
    // Stop the server
    server.stop();
}

