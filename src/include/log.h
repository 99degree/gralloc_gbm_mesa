/*
 * Copyright (C) 2025  Levi Marvin (LIU, YUANCHEN) <levimarvin@icloud.com>
 *
 * Authors:
 *      Levi Marvin (LIU, YUANCHEN) <levimarvin@icloud.com>
 */

#ifndef GRALLOC_GBM_MESA_LOG_H_
#define GRALLOC_GBM_MESA_LOG_H_

#ifndef LOG_TAG
#define LOG_TAG "libgralloc_gm"
#endif

#include <stdio.h>
#include <stdarg.h>

#include <android/log.h>

inline void __log(const int level, const char *format, va_list va) {
    __android_log_vprint(level, LOG_TAG, format, va);
}

inline void log_v(const char *format, ...) {
    va_list va;
    va_start(va, format);
    __log(ANDROID_LOG_VERBOSE, format, va);
    va_end(va);
}

inline void log_d(const char *format, ...) {
    va_list va;
    va_start(va, format);
    __log(ANDROID_LOG_DEBUG, format, va);
    va_end(va);
}

inline void log_i(const char *format, ...) {
    va_list va;
    va_start(va, format);
    __log(ANDROID_LOG_INFO, format, va);
    va_end(va);
}

inline void log_w(const char *format, ...) {
    va_list va;
    va_start(va, format);
    __log(ANDROID_LOG_WARN, format, va);
    va_end(va);
}

inline void log_e(const char *format, ...) {
    va_list va;
    va_start(va, format);
    __log(ANDROID_LOG_ERROR, format, va);
    va_end(va);
}

inline void log_f(const char *format, ...) {
    va_list va;
    va_start(va, format);
    __log(ANDROID_LOG_FATAL, format, va);
    va_end(va);
}

#endif // GRALLOC_GBM_MESA_LOG_H_