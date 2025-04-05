#include <iostream>
#include "klog.h"  // Pastikan untuk menyertakan header file logger Anda

int main() {
    // Membuat instance dari logger
    klog::LOGKEEP logger;

    // Mengatur direktori file log
    logger.setFileDir("my_log.txt");

    // Mengatur penggunaan timestamp
    logger.setTimeStamp(true);

    // Mencatat log dengan berbagai level
    logger.keepLog("Ini adalah pesan normal.", klog::LogLevel::NORMAL);
    logger.keepLog("Ini adalah pesan peringatan.", klog::LogLevel::WARN);
    logger.keepLog("Ini adalah pesan kesalahan.", klog::LogLevel::ERROR);

    // Mencatat log tanpa timestamp
    logger.setTimeStamp(false);
    logger.keepLog("Pesan ini tidak memiliki timestamp.", klog::LogLevel::NORMAL);

    std::cout << "Log telah dicatat ke dalam file." << std::endl;

    return 0;
}