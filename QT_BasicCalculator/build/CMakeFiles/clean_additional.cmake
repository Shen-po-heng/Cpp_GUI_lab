# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\QT_BasicCalculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QT_BasicCalculator_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\test_calculation_Function_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\test_calculation_Function_autogen.dir\\ParseCache.txt"
  "QT_BasicCalculator_autogen"
  "test_calculation_Function_autogen"
  )
endif()
