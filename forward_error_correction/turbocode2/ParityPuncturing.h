#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size>
	class ParityPuncturing
	{
	public:
		static std::bitset<size> Punture(std::bitset<size> stream1, std::bitset<size> stream2)
		{
			std::cout << "Bitwise Parity Puncturing" << std::endl;

			std::bitset<size> output("");

			long long check1 = milliseconds_now();

			for (int i = 0; i < size; i += 2) {
				output[i] = stream1[i];
				if (i + 1 < size) {
					output[i + 1] = stream2[i + 1];
				}
			}

			long long check2 = milliseconds_now();

#if PRINT == 1
			std::cout << output << std::endl;
#endif 

			std::cout << "Size in bytes of the input1: " << sizeof(stream1) << std::endl;
			std::cout << "Size in bytes of the input2: " << sizeof(stream2) << std::endl;
			std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
			std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

			return output;
		}
	};
}
