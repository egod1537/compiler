#ifndef LOGGER_H
#define LOGGER_H

typedef enum { LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR } LogLevel;

void logMsg(LogLevel level, const char *fmt, ...);

#endif // !LOGGER_H
