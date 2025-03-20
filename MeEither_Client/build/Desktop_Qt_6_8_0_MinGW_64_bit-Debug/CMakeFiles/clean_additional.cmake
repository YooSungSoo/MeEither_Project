# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MeEither_Client_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MeEither_Client_autogen.dir\\ParseCache.txt"
  "MeEither_Client_autogen"
  )
endif()
