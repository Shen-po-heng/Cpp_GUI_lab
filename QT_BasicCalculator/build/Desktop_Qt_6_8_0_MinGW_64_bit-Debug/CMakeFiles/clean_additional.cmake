# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QT_BasicCalculatorTest_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QT_BasicCalculatorTest_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\QT_BasicCalculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QT_BasicCalculator_autogen.dir\\ParseCache.txt"
  "QT_BasicCalculatorTest_autogen"
  "QT_BasicCalculator_autogen"
  )
endif()
