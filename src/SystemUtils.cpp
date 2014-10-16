#include "SystemUtils.h"
#include <chrono>


long SystemUtils::getCurrentTime()
{
    return  std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

