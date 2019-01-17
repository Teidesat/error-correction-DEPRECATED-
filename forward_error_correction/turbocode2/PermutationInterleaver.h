#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size>
	class PermutationInterleaver
	{
	public:
		static std::bitset<size> Interleave(std::bitset<size> input, std::vector<short> permutation)
		{
			std::cout << "Bitwise Permutation Interleaver" << std::endl;

			std::bitset<size> output("");

			long long check1 = milliseconds_now();

			for (int i = 0; i < size; i++) {
				output[i] = input[permutation[i]];
			}

			long long check2 = milliseconds_now();

#if PRINT == 1
			std::cout << output << std::endl;
#endif 

			std::cout << "Size in bytes of the input: " << sizeof(input) << std::endl;
			std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
			std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

			return output;
		}
	};
}
