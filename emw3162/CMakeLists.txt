cmake_minimum_required(VERSION 3.13)


set(PORT cortex-m)
set(CPU stm32)
set(CORTEX m3)
set(NANO 1)
set(LD_SCRIPTS stm32.ld)

include(../../picoos/cmake/ToolchainInit.cmake)


project(blink_test)
set(DIR_CONFIG ${CMAKE_CURRENT_SOURCE_DIR})
set(CMSIS_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/../../cmsis-ports/stm32f2xx)
add_peer_directory(${PICOOS_DIR})
add_peer_directory(../../picoos-micro)

add_executable(${PROJECT_NAME} startup.c main.c ../common/test.c)
target_link_libraries(${PROJECT_NAME} picoos picoos-micro)
target_include_directories(${PROJECT_NAME} PRIVATE ../common)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND  arm-none-eabi-objcopy -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND  arm-none-eabi-size ${PROJECT_NAME}.elf)
