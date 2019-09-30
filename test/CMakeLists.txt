add_executable(tests test_main.cpp test_encoder.cpp test_decoder.cpp test_channel.cpp test_datablock.cpp)

target_link_libraries(tests src)
target_link_libraries(tests Catch2)
