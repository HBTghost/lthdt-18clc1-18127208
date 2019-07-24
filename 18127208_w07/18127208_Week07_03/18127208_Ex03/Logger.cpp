#include "Logger.h"

#include "TextFileWriter.h"

#include <conio.h>
#include <iomanip>
#include <iostream>

// include mutex - thread

namespace util {
    static Logger* spLogger_ = nullptr;
} // namespace util

using namespace util;

Logger::Logger(const std::string & filename) :
Singleton( LOGGER ),
filename_( filename ),
maxCharLength_( 0 ),
unknownLogType_( "UNKNOWN" ) {
    // Order MUST MATCH Types in Logger::Type
    logTypes_[0] = "Info";
    logTypes_[1] = "Warning";
    logTypes_[2] = "Error";

    // Find widest log type string
    maxCharLength_ = static_cast<unsigned int>( unknownLogType_.size() );
    for( const std::string& logType : logTypes_) {
        if (maxCharLength_ < logType.size()) {
            maxCharLength_ = static_cast<unsigned int>( logType.size() );
        }
    }

    // critical section - mutex - thread lock


    // Start Log File
    TextFileWriter file(filename, false, false);

    spLogger_ = this;
}

Logger::~Logger() {
    spLogger_ = nullptr;

    // remove critical section or destroy mutex - lockguard, thread etc.
}

void Logger::log(const std::string & text, Type type) {
    log(text.c_str(), type);
}

void Logger::log(const std::ostringstream & stream, Type type) {
    log(stream.str().c_str(), type);
}

#include <Windows.h>

void Logger::log(const char * text, Type type) {
    if (nullptr == spLogger_) {
        std::cout << "Logger has not been initialized, can not log " << text << std::endl;
    }

    // block thread


    // Choose Log Type text string, display "UNKNOWN" if Type is out of range.
    std::ostringstream stream;
    stream << std::setfill(' ') << std::setw(spLogger_->maxCharLength_);

    try {
        stream << spLogger_->logTypes_.at(type);
    } catch (...) {
        stream << spLogger_->unknownLogType_;
    }

    // I am currently in the process of removing Windows specific code:
    // I am trying to do something similar to the date & time code below
    // but in a more generic, portable and cross - platform way using
    // only stand library code.

    // Date & Time
    SYSTEMTIME time;
    GetLocalTime(&time);

    stream << " [" << time.wYear << '.'
        << std::setfill('0') << std::setw(2) << time.wMonth << '.'
        << std::setfill('0') << std::setw(2) << time.wDay << ' '
        << std::setfill(' ') << std::setw(2) << time.wHour << ':'
        << std::setfill('0') << std::setw(2) << time.wMinute << ':'
        << std::setfill('0') << std::setw(2) << time.wSecond << '.'
        << std::setfill('0') << std::setw(3) << time.wMilliseconds << "] ";

    stream << text << std::endl;

    std::cout << stream.str();

    // Save message to log file
    try {
        TextFileWriter file(spLogger_->filename_, true, false);
        file.write(stream.str());
    } catch (...) {
        // Not saved in log file, write message to console
        std::cout << __FUNCTION__ << " failed to write to file: " << stream.str() << std::endl;
    }
}