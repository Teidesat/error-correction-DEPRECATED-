#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size, int blocks>
	class RSCEncoder
	{
	public:
		// Static Function
		// Template parameters:
		//		Size: Length of the input and output bitset.
		//		Blocks: Number of blocks used to encode the input.
		// Parameters:
		//		Input: A bitset with the value of the bits to encode.
		// Description:
		//		Returns a bitset with the values of the input bitset encoded with the RSC encoder.
		// Note:
		//		Prints the output bitset values if PRINT constant value is set to TRUE (Utils.h).
		//		Prints memory management and computing performance stats.
		static std::bitset<size> Encode(std::bitset<size> input)
		{
			std::cout << "Bitwise RSC Encoder" << std::endl;

			long long check1 = Utils::milliseconds_now();

			std::bitset<size> output;
			//std::bitset<blocks> k = Utils::create_bitset_from_string<blocks>(std::string(INITIAL_CONTENT));
			std::bitset<blocks> k = Utils::create_bitset_from_string<blocks>(std::string(blocks, '0'));

			long long check2 = Utils::milliseconds_now();

			for (int i = 0; i < size; i++) {
				int sum = 0;
				for (int j = 0; j < blocks; j++) {
					sum += k[j];
				}

				output[i] = ((input[i] + (sum % 2)) + k[blocks - 1]) % 2;

				for (int j = blocks - 1; j > 0; j--)
				{
					k[j] = k[j - 1];
				}
				k[0] = (input[i] + (sum % 2)) % 2;
			}

			long long check3 = Utils::milliseconds_now();

			Utils::print_bitset(output);

			std::cout << "Size in bytes of the input: " << sizeof(input) << std::endl;
			std::cout << "Size in bytes of the blocks: " << sizeof(k) << std::endl;
			std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
			std::cout << "Declaration time(ms): " << check2 - check1 << std::endl;
			std::cout << "Computation time(ms): " << check3 - check2 << std::endl;

			return output;
		}
	};
}