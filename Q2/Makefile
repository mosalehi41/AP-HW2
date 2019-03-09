CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14

SOURCE1 = quickSort
# ADDITIONAL SOURCES GO HERE ...


OBJECTS = main.o

TARGET = main


$(TARGET): 	 $(OBJECTS)
	   	 $(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
		 rm -f $(OBJECTS)

main.o:    	 main.cpp
	   	 $(CXX) $(CXXFLAGS) main.cpp

clean:
	   	 rm -f $(TARGET) $(OBJECTS)
