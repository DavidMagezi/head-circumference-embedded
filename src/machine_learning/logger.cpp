//Copyright (2023) Dr. David A. Magezi

#include <dlib/misc_api.h>

#include "machine_learning/logger.h"

namespace MachineLearning{
void Logger::display_error_message(std::string error){
    error_log_ << dlib::LINFO << error; //dlib::LERROR
}

void Logger::display_info_message(std::string info){
    info_log_ << dlib::LINFO << info;
}

void Logger::display_test_message(){
    test_log_ << dlib::LINFO << "1 of 4: Testing Logger: This is an informational message";
    test_log_ << dlib::LINFO << "2 of 4: The program will pause for half a second";
    dlib::sleep(500);
    test_log_ << dlib::LINFO << "3 of 4: The program has restarted";
    test_log_ << dlib::LINFO << "4 of 4: The test is complete";
}

void Logger::set_levels(){
    error_log_.set_level(dlib::LALL);
    info_log_.set_level(dlib::LALL);
    test_log_.set_level(dlib::LALL);
}

dlib::logger Logger::error_log_("ERROR");
dlib::logger Logger::info_log_("INFO");
dlib::logger Logger::test_log_("TEST");
}//namespace MachineLearning
