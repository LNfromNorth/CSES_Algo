# 编译器设置
CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra -g

# 源文件目录和构建目录
SRC_DIR := .
BUILD_DIR := build

# 查找所有.cc文件
SRCS := $(shell find $(SRC_DIR) -name '*.cc')

# 生成对应的目标文件路径
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

# 生成对应的可执行文件路径（去掉.o后缀）
EXECS := $(patsubst $(BUILD_DIR)/%.o,$(BUILD_DIR)/%,$(OBJS))

# 默认目标：编译所有可执行文件
all: $(EXECS)

# 规则：从.cc文件编译为.o文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@echo "CC" $<
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# 规则：从.o文件链接为可执行文件
$(BUILD_DIR)/%: $(BUILD_DIR)/%.o
	@echo "LD" $<
	@$(CXX) $(CXXFLAGS) $^ -o $@

# 清理构建文件
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
