cmake_minimum_required(VERSION 3.22.3)
project(ece_city_1_h C)

set(CMAKE_C_STANDARD 11)

add_executable(ece_city_1_h test1.c)

set(CMAKE_CXX_STANDARD 14)

IF(WIN32)
    target_link_libraries(ece_city_1_h -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/opt/homebrew/Cellar/allegro/5.2.8.0_2/include)
    LINK_DIRECTORIES(/opt/homebrew/Cellar/allegro/5.2.8.0_2/lib)
    file(GLOB LIBRARIES "//opt/homebrew/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(ece_city_1_h ${LIBRARIES})
ENDIF(WIN32)