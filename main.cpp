#include "containers.h"
int main()
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
    Queue::Queue New_Playlist;
    for (int i = 0; i < 5; i++)
    {
        New_Playlist.enqueue("UNKNOWN ARTIST - TOP SECRET SONG");
    }
    New_Playlist.empty();
    return 0;
}