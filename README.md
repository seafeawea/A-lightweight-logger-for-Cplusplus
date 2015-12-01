#A LightWeight Logger for C++
- How to use?  
    Just include the header file logger.h and add logger.cpp into your project  
    Set your logger path in logger.cpp
- Write Message:  
Use the fuction Logger::WriteLogger(const string& data)
- Write Message with timestamp:  
Use the function Logger::WriteLogger(const string& data)
- Flush logger. 
Use the function: Logger::flush()


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
		    Logger::WriteLogger("This is a test!\r\n");
		    thread test(foo);
		    Logger::WriteLoggerWithTime("Time test!\r\n");
		    Logger::WriteLoggerWithTime("Time test!\r\n");
		    Logger::WriteLoggerWithTime("Time test!\r\n");
		    Logger::WriteLoggerWithTime("Time test!\r\n");
		    Logger::WriteLoggerWithTime("Time test!\r\n");
		    Logger::WriteLoggerWithTime("Time test!\r\n");
		    test.join();
		    return 0;
	}  
#Result:
	This is a test!  
	Sun Nov 29 21:35:39 2015: Time test!  
	Sun Nov 29 21:35:39 2015: Thread test!  
	Sun Nov 29 21:35:39 2015: Time test!  
	Sun Nov 29 21:35:39 2015: Time test!  
	Sun Nov 29 21:35:39 2015: Time test!  
	Sun Nov 29 21:35:39 2015: Time test!  
	Sun Nov 29 21:35:39 2015: Time test!
