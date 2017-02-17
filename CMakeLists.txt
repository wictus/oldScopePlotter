project(oldscopehistoplotter)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

find_package(ROOT REQUIRED COMPONENTS Hist Gpad Graf MathCore) 

include(${ROOT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(plotter SHARED plotter.cpp)
target_link_libraries(plotter ${ROOT_LIBRARIES})

add_library(histoPlotter SHARED histoPlotter.cpp)
target_link_libraries(histoPlotter ${ROOT_LIBRARIES} plotter)

add_library(specificPlotters SHARED specificPlotters.cpp)
target_link_libraries(specificPlotters ${ROOT_LIBRARIES} plotter histoPlotter)

add_executable(oldscopehistoplotter main.cpp)

target_link_libraries(oldscopehistoplotter histoPlotter plotter specificPlotters)

