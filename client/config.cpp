#include <algorithm>
#include "config.h"

Config::Config(const std::string& file_name)
{
    if (file_name == "") {
        config_file_ = getenv("HOME");
        config_file_ += "/.syncmanrc";
    }
    else {
        config_file_ = file_name;
    }
}

bool Config::read()
{
    std::ifstream file(config_file_, std::ios_base::in);
    if (file.fail()) {
        return false;
        //throw std::runtime_error("Could not open config-file '" + config_file_ + "'!");
    }
    file >> json;
    for (auto&& value : needed_values_) {
        if (json[value] == Json::nullValue) {
            std::cerr << "The value for '" + value + "' is not defined!" << std::endl;
        }
    }
    std::cout << "Config file read." << std::endl;
    file.close();
    return true;
}

void Config::write() const
{
    std::ofstream file(config_file_, std::ios_base::out);
    file << json;
    std::cout << "Config file written." << std::endl;
    file.close();
}

void Config::print() const
{
    std::cout << json << std::endl;
}

void Config::setup()
{
    std::cout << yes_no_question("test", 0);
    std::cout << "Hey there!" << std::endl;
    std::cout << "It looks like you have never run SyncMan before (there is no .syncmanrc file in your homedirectory)." << std::endl;
    std::cout << "This is the setup assistant, it will setup the config file for you." << std::endl;
    std::string server = Config::value_question<std::string>("Which server would you like to use?");
    json["server"] = server;
    write();
}

bool Config::yes_no_question(const std::string& question, const int default_value)
{
    std::string def = "[y,n]";
    bool def_answer;
    switch (default_value) {
        case 1:
            def = "[Y,n]";
            def_answer = true;
            break;
        case 0:
            def = "[y,N]";
            def_answer = false;
            break;
        default:
            break;
    }
    std::cout << question << " " << def << std::endl;
    std::string answer;

    while (true) {
        getline(std::cin, answer);
        if (answer.empty() and default_value != -1) {
            return def_answer;
        }
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        if (answer == "n" or answer == "no") {
            return false;
        }
        else if (answer == "y" or answer == "yes") {
            return true;
        }
        break;
    }
}
