add_library(src FEC/Modules/Module.tcc FEC/Modules/Module.h FEC/Modules/Encoders/Encoder.h FEC/Modules/Decoders/Decoder.h FEC/Modules/Channels/Channel.h FEC/DataBlock.tcc FEC/DataBlock.h FEC/Pipe.tcc FEC/Pipe.h FEC/Modules/Sources/RandomSource.tcc FEC/Modules/Sources/RandomSource.h FEC/Modules/Sources/Source.tcc FEC/Modules/Sources/Source.h FEC/Modules/Utils/Printer.tcc FEC/Modules/Utils/Printer.h FEC/Modules/Interleaves/Interleaver.h FEC/Modules/Sinks/Sink.h FEC/Modules/Interleaves/BlockInterleaver.tcc FEC/Modules/Interleaves/BlockInterleaver.h)
set_target_properties(src PROPERTIES LINKER_LANGUAGE CXX)

add_executable(fec main.cpp)

target_link_libraries(fec src)
