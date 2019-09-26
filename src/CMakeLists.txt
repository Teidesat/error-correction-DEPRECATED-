add_library(src FEC/Encoder.cpp FEC/Encoder.h FEC/Decoder.cpp FEC/Decoder.h FEC/Channel.cpp FEC/Channel.h)

add_executable(fec main.cpp)

target_link_libraries(fec src)
