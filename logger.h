#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "mbed.h"
#include "BufferedSerial.h"

#if defined LOG_TRACE
#define TRACE(x, ...) std::printf("[TRACE: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define DEBUG(x, ...) std::printf("[DEBUG: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define INFO(x, ...) std::printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define WARN(x, ...) std::printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

#elif defined LOG_DEBUG
#define TRACE(x, ...)
#define DEBUG(x, ...) std::printf("[DEBUG: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define INFO(x, ...) std::printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define WARN(x, ...) std::printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

#elif defined LOG_INFO
#define TRACE(x, ...)
#define DEBUG(x, ...)
#define INFO(x, ...) std::printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define WARN(x, ...) std::printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

#elif defined LOG_WARN
#define TRACE(x, ...)
#define DEBUG(x, ...)
#define INFO(x, ...)
#define WARN(x, ...) std::printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
#define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

#elif defined LOG_ERROR
#define TRACE(x, ...)
#define DEBUG(x, ...)
#define INFO(x, ...)
#define WARN(x, ...)
#define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

#else
#define TRACE(x, ...)
#define DEBUG(x, ...)
#define INFO(x, ...)
#define WARN(x, ...)
#define ERROR(x, ...)
#endif

class SerialLogger {

    private: 
        BufferedSerial *pc;
    
    public:
        SerialLogger() {
            pc = new BufferedSerial(USBTX, USBRX);    
        }
        
        void start(int baudRate = 460800) {
            pc->set_baud(baudRate);
        }
};


#endif
