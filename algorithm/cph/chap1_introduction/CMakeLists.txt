# add the executable
add_executable(01.code_template 01.code_template.cpp)
add_executable(02.input_output 02.input_output.cpp)
configure_file(config/config.h.in config.h)

# include_directories applies to all the targets in a particular CMakeLists.txt file
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
)

# The configured file will be written into the binary tree,
# We must add that directory to the list of paths to search for include file
# target_include_directories(01.code_template PUBLIC
#                             "${CMAKE_CURRENT_BINARY_DIR}"
#                            )
