add_library(src FEC/Modules/Module.cpp FEC/Modules/Module.h FEC/Modules/Encoders/Encoder.h FEC/Modules/Decoders/Decoder.h FEC/Modules/Channels/Channel.h FEC/DataBlock.cpp FEC/DataBlock.h FEC/Pipe.cpp FEC/Pipe.h FEC/Modules/Sources/RandomSource.cpp FEC/Modules/Sources/RandomSource.h FEC/Modules/Sources/Source.cpp FEC/Modules/Sources/Source.h FEC/Modules/Utils/Printer.cpp FEC/Modules/Utils/Printer.h FEC/Modules/Interleaves/Interleaver.h FEC/Modules/Sinks/Sink.h FEC/Modules/Interleaves/BlockInterleaver.cpp FEC/Modules/Interleaves/BlockInterleaver.h FEC/Modules/Encoders/RSCEncoder.cpp FEC/Modules/Encoders/RSCEncoder.h)
set_target_properties(src PROPERTIES LINKER_LANGUAGE CXX)

add_executable(fec main.cpp)

target_link_libraries(fec src)
