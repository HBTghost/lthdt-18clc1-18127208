#include "Logger.h"
#include "ExceptionHandler.h"

int main() {
	try {
		Logger log("log.txt");

		Logger::log("Hello World!"); // Default Info Type
		Logger::log("Hello World!, Logger::INFO ); // Explicitly Stating Info Type
			Logger::log("Hello World!, Logger::WARNING ); // Warning Type
				Logger::log("Hello World!, Logger::ERROR ); // Error Type

					// And since my ExceptionHandler also uses the Logger

					ExceptionHandler("Good Bye Cruel World!");

	}
	catch (ExceptionHandler& e) {
		std::cout << "Exception Thrown: " << e.getMessage() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		// Mind you I believe __FUNCTION__ is Windows or Visual Studio specific.
		// I've tried using __PRETTY_FUNCTION__ but for my purposes the formatting
		// wasn't quite right. You can use your desired choice.  
		std::cout << __FUNCTION__ << " Caught Unknown Exception" << std::endl;
	}
}