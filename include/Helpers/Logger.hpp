#pragma once
#include <Arduino.h>
#include <cstdarg>
#include <functional>

namespace depuydt {

using LoggerFn = std::function<void(int, const char *, int, String, va_list)>;
extern LoggerFn logger_;
void setLogger(LoggerFn logger);

}  // namespace depuydt
