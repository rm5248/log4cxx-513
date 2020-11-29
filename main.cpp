#include <log4cxx/dailyrollingfileappender.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/logger.h>
#include <thread>

int main( int argc, char** argv ){
    log4cxx::DailyRollingFileAppenderPtr debugRollingFileAppender1(new log4cxx::DailyRollingFileAppender()); //Create the date pattern in the folder structure.
    std::string aDatePattern = std::string("/tmp/log4cxxtest/") + "%Y%m%d//%H//" + "test.log";

    LOG4CXX_DECODE_CHAR(aTempLogDatePattern, aDatePattern);
    debugRollingFileAppender1->setDatePattern(aTempLogDatePattern);

    log4cxx::helpers::Pool pool; log4cxx::PatternLayoutPtr debugLayout(new log4cxx::PatternLayout());
    debugLayout->setConversionPattern(LOG4CXX_STR("%d [%t] %5p %m%n"));

    debugRollingFileAppender1->setLayout(debugLayout);
    debugRollingFileAppender1->activateOptions(pool);

    log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("LogInfo");
    logger->addAppender(debugRollingFileAppender1);
    logger->setLevel(log4cxx::Level::getInfo());

    while( 1 ){
        LOG4CXX_INFO( logger, "This is a test message" );
        std::this_thread::sleep_for( std::chrono::seconds( 30 ) );
    }
}
