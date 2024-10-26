CXX := g++
-CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude
LDFLAGS := -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCDIR := src
INCDIR := include
OBJDIR := build/obj
BINDIR := build
TARGET := $(BINDIR)/chase

SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)
	@echo "Build successful!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "Cleaned up build files."

rebuild: clean all

.PHONY: all clean rebuild
