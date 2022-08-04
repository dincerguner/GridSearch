project(gridsearch)

set(GRIDSEARCH_HEADER_FILES
    GridSearch.h
    )

set(GRIDSEARCH_SOURCE_FILES
    GridSearch.cpp
    )

set(GRIDSEARCH_BUILD_LIBRARIES
    m
)

add_library(${PROJECT_NAME} STATIC  ${GRIDSEARCH_HEADER_FILES} ${GRIDSEARCH_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE
             ${GRIDSEARCH_BUILD_LIBRARIES}
             ) 
             
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${JSON_INCLUDE_DIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

