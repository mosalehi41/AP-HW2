CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14

SOURCE1 = DataBase
SOURCE2 = quickSort
# ADDITIONAL SOURCES GO HERE ...


OBJECTS = main.o $(SOURCE1).o $(SOURCE2).o

TARGET = main


$(TARGET): 	 $(OBJECTS)
	   	 $(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
		 rm -f $(OBJECTS)

main.o:    	 main.cpp
	   	 $(CXX) $(CXXFLAGS) main.cpp
		 

$(SOURCE1).o:    $(SOURCE1).cpp	
	   	 $(CXX) $(CXXFLAGS) $(SOURCE1).cpp

$(SOURCE2).o:    $(SOURCE2).cpp	
	   	 $(CXX) $(CXXFLAGS) $(SOURCE2).cpp

clean:
	   	 rm -f $(TARGET) $(OBJECTS)
