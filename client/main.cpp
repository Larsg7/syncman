#include <iostream>
#include <fstream>
#include "json/json.h"
#include "config.h"

int main()
{
    try {
        // check for config
        Config config;
        if (!config.read()) {
            // if no config file found start setup
            config.setup();
        }
        config.print();

        // decide what to do (based on user input)

        // call server

        // update files

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown Error occurred!" << std::endl;
        return 1;
    }

    return 0;
}