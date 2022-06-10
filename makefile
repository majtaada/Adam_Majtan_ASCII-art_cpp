CXX=g++
LD=g++
CXXFLAGS=-Wall -pedantic -std=c++17
LIBS=-lpng -lz -lncurses -pthread

all: psfit

psfit: CAnimation.o CTool.o CEffect.o CEffectDarken.o CEffectLighten.o CEffectNegative.o CEffectConvolution.o CImage.o CImageLibrary.o CFileReader.o CManager.o main.o
	   $(LD) -o $@ $^ $(LIBS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

deps:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

-include Makefile.d