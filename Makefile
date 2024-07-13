# 指定编译器
CC = g++

# 指定编译标志
CFLAGS = -Wall -std=c++11 -g

# 目标文件
TARGET = main

# 默认目标
all: $(TARGET)

# 编译规则
$(TARGET): main.cpp tests.cpp
	$(CC) $(CFLAGS) -o $(TARGET) tests.cpp

# 测试目标
test: tests.cpp main.cpp
	$(CC) $(CFLAGS) -o tests tests.cpp
	./tests

# 清理规则
clean:
	rm -f $(TARGET) tests