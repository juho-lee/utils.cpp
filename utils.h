#pragma once

#define BUFFSIZE 1000

#ifdef _WIN32
#if (_MSC_VER >= 1800)
#define foreach(it, container) for (auto &it : container)
#else
#define foreach(it, container) for each (auto &it in container)
#endif
#else
#define foreach(it, container) for (auto &it : container)
#endif

#define ElapsedSecs(bc) ((double)(clock() - bc)/CLOCKS_PER_SEC)

#include <cstdio>
#include <cstdarg>
inline void mysprintf(char *buff, const char *fmt, ...)
{
#ifdef _WIN32
#else
    std::va_list arg;
    va_start(arg, fmt);
    std::vsnprintf(buff, BUFFSIZE, fmt, arg);
    va_end(arg);
#endif
}

#include "math.h"
#include "random.h"
