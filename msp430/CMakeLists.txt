cmake_minimum_required(VERSION 3.12)

set(PORT msp430)
set(NANO 1)
set(MCU msp430f2274)
#set(MCU cc430f5137)
#set(MCU msp430fg4619)
#set(MCU msp430g2533)


include(../../picoos/cmake/ToolchainInit.cmake)

project(blink_test)
set(DIR_CONFIG ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(${PICOOS_DIR} picoos)
add_subdirectory(../../picoos-micro picoos-micro)

add_executable(${PROJECT_NAME} main.c ../common/test.c)
target_link_libraries(${PROJECT_NAME} picoos picoos-micro)
target_include_directories(${PROJECT_NAME} PRIVATE ../common)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND arm-none-eabi-size ${PROJECT_NAME}.elf)
