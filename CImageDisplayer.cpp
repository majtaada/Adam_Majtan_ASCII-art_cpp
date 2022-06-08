#include "CImageDisplayer.hpp"


void CImageDisplayer::showImage( CImage & image)
{
    if ( (mainwin = initscr()) == NULL ) 
	    throw std::invalid_argument("Nejde obrazovka");
    height=image.getHeight();
    width=image.getWidth();
    noecho();
    keypad(mainwin, TRUE);
    
}