//Copyright (2023) Dr. David A. Magezi

#ifndef DEF_LOGGER
#define DEF_LOGGER

#include <string>

#include <dlib/logger.h>

class Logger{
public:
    static void display_error_message(std::string error);
    static void display_info_message(std::string info);
    static void display_test_message();
    static void set_levels();

private:
    static dlib::logger error_log_;
    static dlib::logger info_log_;
    static dlib::logger test_log_;
};

#endif //DEF_LOGGER
