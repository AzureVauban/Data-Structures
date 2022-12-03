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
    printQueue(Playlist);
    for (int i = queue.getSize(); i > 0; i--)
    {
        std::cout << queue.getData() << std::endl;
        queue.dequeue();
    }
    Playlist.
}
return 0;
