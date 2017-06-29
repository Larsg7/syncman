#ifndef SYNCMAN_CONFIG_H
#define SYNCMAN_CONFIG_H


#include <json/json.h>
#include <iostream>
#include <fstream>

class Config
{
public:
    Json::Value json;

    Config(const std::string& file_name = "");

    bool read();

    void write() const;

    void print() const;

    void setup();

private:
    template<typename T>
    static T value_question(const std::string& question)
    {
        T answer;
        std::cout << question << std::endl;
        while (true) {
            std::cin >> answer;
            if (std::cin.fail()) {
                std::cout << "Invalid input!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            break;
        }
        return answer;
    }

    bool yes_no_question(const std::string& question, const int default_value = -1);

    std::string config_file_;
    std::vector<std::string> needed_values_ = {
            "server"
    };
};


#endif //SYNCMAN_CONFIG_H
