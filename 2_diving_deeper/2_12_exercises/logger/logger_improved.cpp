#include <iostream>
#include <chrono>
#include <iomanip>          // put_time
#include <source_location>

// --- DestinationPolicy
// --- StandardOut
// --- StandardCerr

class DestinationPolicy {
public:
    virtual std::ostream& getDestination() = 0;
};

class StandardOut : public DestinationPolicy {
public:
    std::ostream& getDestination() {
        return std::cout;
    }
};

class StandardCerr : public DestinationPolicy {
public:
    std::ostream& getDestination() {
        return std::cerr;
    }
};


// ---- TimestampPolicy
// ---- Timestamp
// ---- NoTimestamp

class TimestampPolicy {
public:
    virtual void timestamp(std::ostream& out) = 0;
};

class Timestamp : public TimestampPolicy {
public:    
    void timestamp(std::ostream& out) {
        using namespace std::chrono;
        time_t now = system_clock::to_time_t(system_clock::now());
        out << std::put_time(std::localtime(&now), "%F %T");
        out << " ";
    }
};

class NoTimestamp : public TimestampPolicy {
public:
    void timestamp(std::ostream& out) {}
};


// ---- DetailsPolicy
// ---- Extensive
// ---- Basic

class DetailsPolicy {
protected:
    virtual void getInfo(std::ostream& os, 
                         const std::source_location location = 
                         std::source_location::current()) = 0;
};

class ExtensiveInfo : public DetailsPolicy {
public:
    void getInfo(std::ostream& os,
                 const std::source_location location = 
                 std::source_location::current()) {
        
        os << "file: "
           << location.file_name() << "("
           << location.line() << ":"
           << location.column() << ") \n`"
           << location.function_name() << "\n";
    }
};

class BasicInfo : public DetailsPolicy {
public: 
    void getInfo(std::ostream& os,
                 const std::source_location location = 
                 std::source_location::current()) {}
};



template <typename Destination, typename Timestamp, typename Details>
class Logger : public Destination, public Timestamp, public Details {
private:
    std::ostringstream oss_;
    void resetOss() { 
        oss_.str("");  
        oss_.clear();
    }

public:
    template <typename... Args>
    void log(Args&&... args) {
        
        this->timestamp(oss_);
        (oss_ << ... << std::forward<Args>(args)) << "\n";
        this->getInfo(oss_);

        // write info to std::cout or std::cerr
        this->getDestination() << oss_.str() << "\n";
        resetOss();
    }
}; 

int main() {
    std::cout << "Logging... \n";

    Logger<StandardOut, Timestamp, BasicInfo> log1;
    log1.log("Message with timestamp");

    Logger<StandardCerr, Timestamp, BasicInfo> log2;
    log2.log("Message on std::cerr with timestamp");

    Logger<StandardOut, Timestamp, ExtensiveInfo> log3;
    log3.log("Message with timestamp and full info");

    Logger<StandardOut, NoTimestamp, ExtensiveInfo> log4;
    log4.log("Message without timestamp and with full info");

    Logger<StandardOut, Timestamp, BasicInfo> log5;
    log5.log("Variadic ", "Message ",  "with ", "timestamp ", "log ", 5);


    return 0;
}