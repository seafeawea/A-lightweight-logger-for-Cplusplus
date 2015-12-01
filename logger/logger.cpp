//
//  logger.cpp
//  logger
//
//  Created by XZ on 15/11/29.
//  Copyright © 2015年 XZ. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <mutex>
#include "logger.h"

const string LoggerPath = "./logger.txt";
mutex loggerMtx;
const char * GetCurrentTime();

Logger::Logger() {
    mylogger.open(LoggerPath, ios::out|ios::app);
}
Logger::~Logger() {
    try {
        mylogger << flush;
        mylogger.close();
    } catch (exception & e) {
        cout.write(GetCurrentTime(), 24);
        cout << ": flush logger error. Error is:"<< e.what() << endl;

    }
}

Logger & Logger::GetInstance() {
    static Logger _instance;
    return _instance;
}

int Logger::WriteLogger(const string & data) {
    try {
        loggerMtx.lock();
        GetInstance().mylogger << data;
    } catch (exception & e) {
        cout << "Write logger error. Error is:"<< e.what() << endl;
        loggerMtx.unlock();
        return WriteERROR;
    }
    loggerMtx.unlock();
    return WriteOK;
}

int Logger::WriteLoggerWithTime(const string & data) {
    try {
        loggerMtx.lock();
        GetInstance().mylogger.write(GetCurrentTime(), 24);
        GetInstance().mylogger << ": " << data;
    } catch (exception & e) {
        cout.write(GetCurrentTime(), 24);
        cout << ": Write logger error. Error is:"<< e.what() << endl;
        loggerMtx.unlock();
        return WriteERROR;
    }
    loggerMtx.unlock();
    return WriteOK;
}

int Logger::Flush()
{
    try {
        GetInstance().mylogger << flush;
    } catch (exception & e) {
        cout.write(GetCurrentTime(), 24);
        cout << ": Flush logger error. Error is:"<< e.what() << endl;
        return WriteERROR;
    }
    return WriteOK;
}

const char * GetCurrentTime() {
    static time_t rawtime;
    //static struct tm * timeinfo;
    time ( &rawtime );
    return asctime(localtime(&rawtime));
}