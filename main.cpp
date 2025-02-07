#include <iostream>
#include <sstream>
#include "test.h"
#include <thread>

typedef unsigned long long ULL;

std::string getThreadIdOfString(const std::thread::id & id)
{
    std::stringstream sin;
    sin << id;
    return sin.str();
}

ULL getThreadIdOfULL(const std::thread::id & id)
{
    return std::stoull(getThreadIdOfString(id));
}

int main() {
    std::thread::id id = std::this_thread::get_id();
    printf("cout ----- id : %llu \n", id);
    std::cout << "cout ----- id : " << id << std::endl;
    std::cout << "getThreadIdOfString ----- id : " << getThreadIdOfString(id) << std::endl;
    std::cout << "getThreadIdOfULL ----- id : " << getThreadIdOfULL(id) << std::endl;
    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.