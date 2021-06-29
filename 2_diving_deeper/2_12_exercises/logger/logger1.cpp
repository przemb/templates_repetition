#include <iostream>
#include <ctime>
#include <cstring>

// DestinationPolicy 
// -- consoleLogger
// -- noLogger

class DestinationPolicy {
protected:
    virtual void print(const std::string& msg) = 0;
};

class ConsoleLogger : public DestinationPolicy {
protected:
    void print(const std::string& msg) override {
        std::cout << msg << "\n";
    }
};

class NoLogger : public DestinationPolicy {
protected:
    void print(const std::string& msg) override { }
};

// TimestampPolicy
// -- timestamp
// -- noTimestamp

class TimestampPolicy {
protected:
    virtual std::string timestamp() = 0; 
};

class Timestamp : public TimestampPolicy {
protected:
    std::string timestamp() override {
        auto result = std::time(nullptr);
        auto tm = std::ctime(&result);
        tm[strlen(tm)-1] = '\0';

        return (std::string(tm) + " ");
    }
};

class NoTimestamp : public TimestampPolicy {
protected:
    std::string timestamp() override {
        return "";
    }
};

// Logger
template <typename Destination, typename Timestamp>
class Logger : public Destination, public Timestamp {
public:
    Logger() {}
    void log(const std::string& msg) {
        const auto timestamp = this->timestamp();
        this->print(timestamp + msg);
        std::cout << "----------------------- \n";
    }
};

int main() {
    std::cout << "Logging... \n";

    Logger<ConsoleLogger, Timestamp> logger1;
    logger1.log("Message with timestamp");

    Logger<ConsoleLogger, NoTimestamp> logger2;
    logger2.log("Message without timestamp");

    Logger<NoLogger, Timestamp> logger3;
    logger3.log("Should not appear");

    return 0;
}