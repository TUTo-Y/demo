# 定义编译器
CC = gcc

# 定义编译选项
CFLAGS = -Wall -O2

# 定义目录
SRCDIR = src
OBJDIR = obj
LIBDIR = lib

# 定义目标文件
TARGET = $(LIBDIR)/libdemo.a

# 查找所有源文件
SRCS = $(wildcard $(SRCDIR)/*.c)

# 查找所有头文件
INCS = $(wildcard $(SRCDIR)/*.h)

# 将源文件名替换为目标文件名
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# 默认目标
all: $(TARGET)
	cp lib/* ~/lib
	cp src/*.h ~/include

# 生成静态库
$(TARGET): $(OBJS)
	@mkdir -p $(LIBDIR)
	ar rcs $@ $^

# 编译源文件
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/*.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理目标文件
clean:
	rm -rf $(OBJDIR) $(LIBDIR)
	rm -rf test

.PHONY: all clean

# 测试
test:example/test.c
	$(CC) example/test.c -o test -ldemo