cmake_minimum_required(VERSION 3.13)
project( log4cxx-513 )

include( FindPkgConfig )

pkg_check_modules( log4cxx REQUIRED liblog4cxx )

add_executable( log4cxx-513-test main.cpp )
target_link_libraries( log4cxx-513-test ${log4cxx_LIBRARIES} )
