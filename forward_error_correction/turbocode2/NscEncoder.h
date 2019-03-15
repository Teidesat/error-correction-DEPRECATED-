#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size, int blocks>
	class NSCEncoder
	{
	public:
		// Static Function
		// Template parameters:
		//		Size: Length of the input bitset.
		//		Blocks: Number of blocks used to encode the input.
		// Parameters:
		//		Input: A bitset with the value of the bits to encode.
		// Description:
		//		Returns a bitset with the values of the input bitset encoded with the NSC encoder.
		// Note:
		//		Prints the output bitset values if PRINT constant value is set to TRUE (Utils.h).
		//		Prints memory management and computing performance stats.
		static std::bitset<size * 2> Encode(std::bitset<size> input)
		{
			std::cout << "Bitwise NSC Encoder" << std::endl;

			long long check1 = Utils::milliseconds_now();

			std::bitset<size * 2> output;
			//std::bitset<blocks> k = Utils::create_bitset_from_string<blocks>(std::string(INITIAL_CONTENT));
			std::bitset<blocks> k = Utils::create_bitset_from_string<blocks>(std::string(blocks, '0'));

			long long check2 = Utils::milliseconds_now();

			for (int i = 0; i < size; i++) {
				output[i * 2] = (input[i] + k[blocks - 1]) % 2;

				int sum = input[i];
				for (int j = 0; j < blocks; j++) {
					sum += k[j];
				}
				output[i * 2 + 1] = sum % 2;

				for (int j = blocks - 1; j > 0; j--)
				{
					k[j] = k[j - 1];
				}
				k[0] = input[i];
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