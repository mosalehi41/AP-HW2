CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14

SOURCE1 = Map
# ADDITIONAL SOURCES GO HERE ...


OBJECTS = main.o $(SOURCE1).o

TARGET = main


$(TARGET): 	 $(OBJECTS)
	   	 $(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
		 rm -f $(OBJECTS)


main.o:    	 main.cpp
	   	 $(CXX) $(CXXFLAGS) main.cpp

$(SOURCE1).o:    $(SOURCE1).cpp	
	   	 $(CXX) $(CXXFLAGS) $(SOURCE1).cpp

clean:
	   	 rm -f $(TARGET) $(OBJECTS)
