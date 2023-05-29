#ifndef BELIEN_LOG_H
#define BELIEN_LOG_H

#include <ctime>
#include "Header.h"

static std::string getTime() {
	const char* time_fmt = "%Y-%m-%d %H:%M:%S";
	time_t      t = time(nullptr);
	char        time_str[64];
	strftime(time_str, sizeof(time_str), time_fmt, localtime(&t));

	return time_str;
}

#ifdef BELIEN_LOG_FPRINTF

#define LOGI(format, ...)                                                   \
    fprintf(stderr, "[INFO]%s [%s:%d %s()] " format "\n", getTime().data(), \
            __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define LOGI_(...)                                                   \
    fprintf(stderr, "[INFO]%s [%s:%d %s()] %s\n", getTime().data(), \
	            __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define LOGE(format, ...)                                                    \
    fprintf(stderr, "[ERROR]%s [%s:%d %s()] " format "\n", getTime().data(), \
            __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define LOGE_(...)                                                    \
    fprintf(stderr, "[ERROR]%s [%s:%d %s()] %s\n", getTime().data(), \
            __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#endif

#ifdef BELIEN_LOG_QDENUG

#define LOGI(format, ...)                                                    \
    qDebug("[INFO]%s [%s:%d %s()] " format "\n", getTime().data(), __FILE__, \
           __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define LOGI_(...)                                                             \
    qDebug("[INFO]%s [%s:%d %s()] %s\n", getTime().data(), __FILE__, __LINE__, \
           __FUNCTION__, ##__VA_ARGS__)

#define LOGE(format, ...)                                                     \
    qDebug("[ERROR]%s [%s:%d %s()] " format "\n", getTime().data(), __FILE__, \
           __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define LOGE_(...)                                                    \
    qDebug("[ERROR]%s [%s:%d %s()] %s\n", getTime().data(), __FILE__, \
           __LINE__, __FUNCTION__, ##__VA_ARGS__)

#endif

#endif
