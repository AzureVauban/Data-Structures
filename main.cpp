#include "containers.h"
/*
void queue_demo()
{
    // queue demo
    Queue::Queue Playlist;
    Playlist.enqueue("Carpenter Brut - Roller Mobster");
    Playlist.enqueue("Deadlife - Deviant");
    Playlist.enqueue("Perturbator - Raining Steel");
    Playlist.enqueue("Carpenter Brut - End Titles");
    Playlist.enqueue("Deadlife - Downpour");
    Playlist.enqueue("Perturbator - Sexualizer");
    std::cout << "Songs in my Synthwave Music Queue" << std::endl;
    for (int i = Playlist.getSize(); i > 0; i--)
    {
        std::cout << Playlist.getData() << std::endl;
        Playlist.dequeue();
    }
    // empty() test
    Queue::Queue New_Playlist;
    for (int i = 0; i < 5; i++)
    {
        New_Playlist.enqueue("UNKNOWN ARTIST - TOP SECRET SONG");
        Playlist.enqueue("UNKNOWN ARTIST - TOP SECRET SONG");
    }
    New_Playlist.empty();
    //! add a debug point here and see the queues in debug =)
    Playlist.~Queue();
}
*/

int main()
{
    // queue_demo();

    List::List IDEs;
    IDEs.append("Visual Studio Code");
    IDEs.append("Visual Studio");
    IDEs.append("CLion");
    for (int i = IDEs.getSize()*-2; i != IDEs.getSize()*2; i++)
    {
        std::cout << IDEs.getData(i) << std::endl;
    }
    std::cout << "terminating process..." << std::endl;
    return 0;
}