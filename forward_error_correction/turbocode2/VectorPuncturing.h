#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size, int output_size>
	class VectorPuncturing
	{
	public:
		static std::bitset<output_size> Punture(std::bitset<size> stream1, std::bitset<size> punturingVector)
		{
			std::cout << "Bitwise Vector Puncturing" << std::endl;

			std::bitset<output_size> output;
			int counter = 0;

			long long check1 = milliseconds_now();

			for (int i = 0; i < size; i++) {
				if (punturingVector.test(i)) {
					output[counter] = stream1[i];
					counter++;
				}
			}

			long long check2 = milliseconds_now();

#if PRINT == 1
			std::cout << output << std::endl;
#endif 

			std::cout << "Size in bytes of the input: " << sizeof(stream1) << std::endl;
			std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
			std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

			return output;
		}
	};
}
