// Copyright (2023) David A. Magezi

#include <filesystem>
#include <string>

#include "machine_learning/logger.h"
#include "machine_learning/image.h"

int main(int argc, char** argv) {
    Logger::set_levels(); // comment out to suppress output
    Logger::display_test_message();
    if (argc != 2){
        Logger::display_error_message(argv[0]);
        if (argc > 2){
            Logger::display_error_message("Too many arguments");
        }
        Logger::display_error_message("This program needs ULTRASOUND data");
        Logger::display_error_message("Please obtain these from https://zenodo.org/record/1327317/files/");
        Logger::display_error_message("Download, decompress the compressed files, and place them in a folder");
        Logger::display_error_message("Then give that folder as input to this program");
        return 1;
    }

    Image image(argv[1]);
    image.load_data("031_HC.png");

    return 0;
}
