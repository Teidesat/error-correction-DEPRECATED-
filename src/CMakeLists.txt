add_library(src FEC/Modules/Module.cpp FEC/Modules/Module.h FEC/Modules/Encoders/Encoder.h FEC/Modules/Decoders/Decoder.h FEC/Modules/Channels/Channel.h FEC/DataBlock.cpp FEC/DataBlock.h FEC/Pipe.cpp FEC/Pipe.h FEC/Modules/Sources/RandomSource.cpp FEC/Modules/Sources/RandomSource.h FEC/Modules/Sources/Source.cpp FEC/Modules/Sources/Source.h FEC/Modules/Utils/Printer.cpp FEC/Modules/Utils/Printer.h FEC/Modules/Interleavers/Interleaver.h FEC/Modules/Sinks/Sink.h FEC/Modules/Interleavers/BlockInterleaver.cpp FEC/Modules/Interleavers/BlockInterleaver.h FEC/Modules/Encoders/RSCEncoder.cpp FEC/Modules/Encoders/RSCEncoder.h FEC/Modules/Encoders/TurboEncoder.cpp FEC/Modules/Encoders/TurboEncoder.h FEC/Modules/Utils/StatValue.cpp FEC/Modules/Utils/StatValue.h)
set_target_properties(src PROPERTIES LINKER_LANGUAGE CXX)

add_executable(fec main.cpp speed_test.cpp)
add_executable(fec_speed_test speed_test.cpp)

target_link_libraries(fec src)
target_link_libraries(fec_speed_test src)
