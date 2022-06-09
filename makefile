CXX=g++
LD=g++
CXXFLAGS=-Wall -pedantic -std=c++17
LIBS=-ljpeg -lz -lncurses

all: psfit

psfit: CAnimation.o CConverter.o CEffect.o CEffectDarken.o	CEffectLighten.o CEffectNegative.o CImage.o CIMageDisplayer.o CImageLibrary.o CFileReader.o
	   $(LD) -o $@ $^ $(LIBS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

deps:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

-include Makefile.d