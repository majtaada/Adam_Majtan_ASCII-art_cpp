#include "CImage.hpp"
#include "ncurses.h"
class CImageDisplayer
{
private:
    
public:
    void showImage(CImage & image);
    WINDOW * mainwin , childwin;
    int ch,height,width;
};

