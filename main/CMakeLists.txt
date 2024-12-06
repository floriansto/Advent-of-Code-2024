file(GLOB MAIN ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

foreach(FILE ${MAIN})
    get_filename_component(FILENAME ${FILE} NAME_WE)
    add_executable(${FILENAME} ${FILE})
    target_link_libraries(${FILENAME} ${PROJECT_NAME})
endforeach()
