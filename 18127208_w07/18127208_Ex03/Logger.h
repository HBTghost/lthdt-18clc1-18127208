#pragma once

#include "Singleton.h"

#include <array>
#include <string>
#include <sstream>

namespace util {

    class Logger final : public Singleton {
    public:
        enum Type {
            INFO = 0,
            WARNING,
            ERROR
        };

    private:
        std::string filename_;
        unsigned maxCharLength_;

        std::array<std::string, 3> logTypes_;
        const std::string unknownLogType_;

        // CRICTICAL_SECTION  // replace with mutex and lockguard...

    public:
        explicit Logger(const std::string& filename);
        virtual ~Logger();

        Logger(const Logger& c) = delete;
        Logger& operator=(const Logger& c) = delete;

        static void log(const std::string& text, Type type = INFO);
        static void log(const std::ostringstream& stream, Type type = INFO);
        static void log(const char* text, Type type = INFO);
    };

} // namespace util