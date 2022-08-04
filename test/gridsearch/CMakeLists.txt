project(gridsearch.app)

add_executable(${PROJECT_NAME} app.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
            m
            gridsearch
            ) 