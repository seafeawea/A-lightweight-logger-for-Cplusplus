//
//  main.cpp
//  logger
//
//  Created by XZ on 15/11/29.
//  Copyright © 2015年 XZ. All rights reserved.
//

#include <iostream>
#include <string>
#include <thread>
#include "logger.h"
using namespace std;

void foo() {
    Logger::WriteLoggerWithTime("Thread test!\r\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //string test()
    Logger::WriteLogger("This is a test!\r\n");
    thread test(foo);
    //test.detach();
    Logger::WriteLoggerWithTime("Time test!\r\n");
    Logger::WriteLoggerWithTime("Time test!\r\n");
    Logger::WriteLoggerWithTime("Time test!\r\n");
    Logger::WriteLoggerWithTime("Time test!\r\n");
    Logger::WriteLoggerWithTime("Time test!\r\n");
    Logger::WriteLoggerWithTime("Time test!\r\n");
    test.join();
    return 0;
}
