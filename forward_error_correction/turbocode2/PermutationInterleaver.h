#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size>
	class PermutationInterleaver
	{
	public:
		// Static Function
		// Template parameters:
		//		Size: Length of the input and output bitset.
		// Parameters:
		//		Input: A bitset with the value of the bits to interleave.
		//		Permutation: A vector with the order of the interleaved bits.
		// Description:
		//		Returns a bitset with the values of the input bitset interleaved by the Permutation method.
		// Note:
		//		Prints the output bitset values if PRINT constant value is set to TRUE (Utils.h).
		//		Prints memory management and computing performance stats.
		static std::bitset<size> Interleave(std::bitset<size> input, std::vector<short> permutation)
		{
			std::cout << "Bitwise Permutation Interleaver" << std::endl;

			std::bitset<size> output = Utils::create_bitset_from_string<size>(std::string(size, INTERLEAVER_PADDING));

			long long check1 = Utils::milliseconds_now();

			for (int i = 0; i < size; i++) {
				output[i] = input[permutation[i]-1];
			}

			long long check2 = Utils::milliseconds_now();

			Utils::print_bitset(output);

			std::cout << "Size in bytes of the input: " << sizeof(input) << std::endl;
			std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
			std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

			return output;
		}
	};
}
