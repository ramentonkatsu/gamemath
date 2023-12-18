CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = 

SRC_DIR = d:\code\gamemath

TARGET = $(SRC_DIR)/a
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
	rm *.o
	rm *.d

-include $(DEPS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<


.PHONY: run
run: all
	@./$(TARGET)
