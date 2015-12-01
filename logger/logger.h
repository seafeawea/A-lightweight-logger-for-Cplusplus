//
//  logger.h
//  logger
//
//  Created by XZ on 15/11/29.
//  Copyright © 2015年 XZ. All rights reserved.
//

#ifndef logger_h
#define logger_h
#include <string>
#include <fstream>
#include <mutex>
using namespace std;

class Logger {
    enum {
        WriteOK=0,
        WriteERROR=1
    };
    
public:
    static Logger & GetInstance();
    static int WriteLogger(const string & data);
    static int WriteLoggerWithTime(const string & data);
    static int Flush();
    
protected:
    Logger();
    ~Logger();
private:
    fstream mylogger;
    Logger(const Logger & l);
    Logger & operator=(const Logger & l);
};


#endif /* logger_h */
