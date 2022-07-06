#include <fstream>
#include "gtest/gtest.h"

const std::string filename("0002_fstream_test.txt");

TEST(fstream_test, write_test)
{
    std::ofstream out(filename);
    out << "This is one line." << std::endl;
    out << "This is another line." << std::endl;
}

TEST(fstream_test, read_test)
{
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line))
        std::cout << line << std::endl;
}

TEST(fstream_test, copy_test)
{
    std::ifstream in(filename); // 创建一个输出流并打开给定文件

    std::ofstream out; // 创建一个输出流但未与任何文件关联

    std::string copy_filename = filename + ".copy";
    out.open(copy_filename); // 将输出流与指定文件关联

    // 测试是否成功打开文件
    if (out)
        std::cout << "Successfully opened file: " << copy_filename << std::endl;
    else
        std::cout << "Failed to open file: " << copy_filename << std::endl;

    // 复制文件
    std::string line;
    while (std::getline(in, line))
        out << line << std::endl;

    // 关闭文件
    in.close();
    out.close();

    in.close();
    in.open(filename);

    // 打开另外一个文件
    std::string copy_filename2 = filename + ".copy2";
    out.open(copy_filename2); // 将输出流与指定文件关联

    // 测试是否成功打开文件
    if (out)
        std::cout << "Successfully opened file: " << copy_filename2 << std::endl;
    else
        std::cout << "Failed to open file: " << copy_filename2 << std::endl;

    // 复制文件
    while (std::getline(in, line))
        out << line << std::endl;
}

/**
 * @brief 以 out 模式打开文件会清空数据
 */
TEST(fstream_test, truncate_test)
{
    std::ifstream in(filename);
    std::ofstream out(filename + ".copy", std::ofstream::out | std::ofstream::trunc);

    std::string line;
    while (std::getline(in, line))
        out << line << std::endl;
}

/**
 * @brief 以 out + append 模式打开文件来追加数据
 */
TEST(fstream_test, append_test)
{
    std::ifstream in(filename);
    std::ofstream out(filename + ".copy", std::ofstream::out | std::ofstream::app);

    std::string line;
    while (std::getline(in, line))
        out << line << std::endl;
}