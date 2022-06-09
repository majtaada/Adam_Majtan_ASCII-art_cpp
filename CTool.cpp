#include "CTool.hpp"


CTool::CTool ( std::string &asciiTransition ) 
{
    grayLevel = asciiTransition;
}


std::vector<std::vector<char>> CTool::convertToAscii ( std::vector<std::vector<double>> &grayMatrix) const
{
    
    int grayscale;
    int lenght = grayLevel.length() - 1;
    std::vector<std::vector<double>> imageMatrix=grayMatrix;
    std::vector<std::vector<char>> asciiMatrix;
    for ( auto it= imageMatrix.begin(); it != imageMatrix.end(); it++ ) {
        std::vector<char> v1;
        for ( auto it1 = it->begin(); it1 != it->end(); it1++ )
        {
            grayscale = (lenght - 1) * *it1/255 ;
            v1.push_back (grayLevel[grayscale]);  
        }
        asciiMatrix.push_back(v1);
    }   
    return asciiMatrix;
}

std::vector<std::vector<double>> CTool::toGrayScale ( png_structp &pngStr , png_infop &pngInfo ) const
{ 
  int width = png_get_image_width(pngStr, pngInfo);
  int height = png_get_image_height(pngStr, pngInfo);
  int shifter,grayscale;
  std::vector<std::vector<double>> pngMatrix;
  std::cout << width <<  "x" << height << std::endl;
  if (png_get_color_type(pngStr, pngInfo) == PNG_COLOR_TYPE_RGB)
    shifter=3;
  else if(png_get_color_type(pngStr, pngInfo) == PNG_COLOR_TYPE_RGBA)
    shifter=4;
  else{
    throw std::invalid_argument("Neplatny color type");
  }
  png_bytepp rows = png_get_rows(pngStr, pngInfo);
  std::cout << "macka" << std::endl;
  for (int row = 0; row < height; row++){
    std::vector<double> v1;
        // Pixels in RGBA -> x4 , RGB -> x3
    for (int col = 0; col < width * shifter ; col+=shifter)
    {       
      // gray = 0.2126 * red + 0.7152 * green + 0.0722 * blue
      grayscale = int(rows[row][col])*R +  int(rows[row][col+1])*G +  int(rows[row][col+2])*B;
      v1.push_back ( grayscale);  
    }    
    pngMatrix.push_back( v1);
  }
  free(pngStr);
  free(pngInfo);
  free(rows);

  return pngMatrix;
}