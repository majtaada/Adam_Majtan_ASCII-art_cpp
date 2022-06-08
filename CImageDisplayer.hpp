#include "CImage.hpp"
#include <curses.h>
#include <ncurses.h>
#include <vector>
#include <stdexcept>

class CImageDisplayer
{
private:
    
public:
    void showImage(CImage & image);
    WINDOW * mainwin , childwin;
    int ch,height,width;
};

