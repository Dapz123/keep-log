#ifndef LOG_CPP_H
#define LOG_CPP_H

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>

namespace klog {

    
    enum LogLevel {
        NORMAL = 1,
        WARN,
        ERROR
    };

    class LOGKEEP {
    public:         

        void keepLog(std::string text, int level)
        {
            LOG(text, level);
        }

        void setFileDir(std::string directory) {
            getFileDir(directory);
        }

        void setTimeStamp(bool status)
        {
            useTimeStamp(status);
        }

    private:

        std::string file_dir = "keep-log.txt";
        bool timestamp = false;

        void useTimeStamp(bool status)
        {
            timestamp = status;
        }

        std::string currentDateTime()
        {
            auto now = std::chrono::system_clock::now();
            std::time_t now_c = std::chrono::system_clock::to_time_t(now);
            std::ostringstream oss;
            oss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %X");
            return oss.str();
        }

        void LOG(std::string text, int level) {
            std::fstream buffer(file_dir, std::ios_base::app);

            if (timestamp == true) {
                buffer << currentDateTime() << " ";
            }

            if (level == NORMAL) {           // NORMAL MODE
                buffer << "[*] ";
            } else if (level == WARN) {    // WARN MODE
                buffer << "[ warn ] ";
            } else if (level == ERROR) {    // ERROR MODE
                buffer << "[ ERROR ]\n";
            } else {
                buffer << "";
            }

            buffer << text << std::endl;
            buffer.close();
        }

        void getFileDir(std::string directory) {
            file_dir = directory;
        }

    };
}

#endif