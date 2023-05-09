#pragma once
#include <Arduino.h>

namespace depuydt {

#define LOG_LEVEL_NONE 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_INFO 3
#define LOG_LEVEL_CONFIG 4
#define LOG_LEVEL_DEBUG 5
#define LOG_LEVEL_VERBOSE 6
#define LOG_LEVEL_VERY_VERBOSE 7

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_DEBUG
#endif

void sv_log_printf_(int level, const char *tag, int line, const char *format, ...);
void sv_log_printf_(int level, const char *tag, int line, const __FlashStringHelper *format, ...);

#if LOG_LEVEL >= LOG_LEVEL_VERY_VERBOSE
#define sv_log_vv(tag, format, ...) \
  sv_log_printf_(LOG_LEVEL_VERY_VERBOSE, tag, __LINE__, F(format), ##__VA_ARGS__)
#else
#define sv_log_vv(tag, format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_VERBOSE
#define sv_log_v(tag, format, ...) \
  sv_log_printf_(LOG_LEVEL_VERBOSE, tag, __LINE__, F(format), ##__VA_ARGS__)
#else
#define sv_log_v(tag, format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define sv_log_d(tag, format, ...) \
  sv_log_printf_(LOG_LEVEL_DEBUG, tag, __LINE__, F(format), ##__VA_ARGS__)
#define sv_log_config(tag, format, ...) \
  sv_log_printf_(LOG_LEVEL_CONFIG, tag, __LINE__, F(format), ##__VA_ARGS__)
#else
#define sv_log_d(tag, format, ...)
#define sv_log_config(tag, format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define sv_log_i(tag, format, ...) \
  sv_log_printf_(LOG_LEVEL_INFO, tag, __LINE__, F(format), ##__VA_ARGS__)
#else
#define sv_log_i(tag, format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define sv_log_w(tag, format, ...) \
  sv_log_printf_(LOG_LEVEL_WARN, tag, __LINE__, F(format), ##__VA_ARGS__)
#else
#define sv_log_w(tag, format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define sv_log_e(tag, format, ...) \
  sv_log_printf_(LOG_LEVEL_ERROR, tag, __LINE__, F(format), ##__VA_ARGS__)
#else
#define sv_log_e(tag, format, ...)
#endif

#define LOG_E(tag, ...) sv_log_e(tag, __VA_ARGS__)
#define LOG_W(tag, ...) sv_log_w(tag, __VA_ARGS__)
#define LOG_I(tag, ...) sv_log_i(tag, __VA_ARGS__)
#define LOG_D(tag, ...) sv_log_d(tag, __VA_ARGS__)
#define LOG_CONFIG(tag, ...) sv_log_config(tag, __VA_ARGS__)
#define LOG_V(tag, ...) sv_log_v(tag, __VA_ARGS__)
#define LOG_VV(tag, ...) sv_log_vv(tag, __VA_ARGS__)

}  // namespace depuydt
