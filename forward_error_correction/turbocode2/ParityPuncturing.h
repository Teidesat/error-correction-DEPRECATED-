#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size>
	class ParityPuncturing
	{
	public:
		// Static Function
		// Template parameters:
		//		Size: Length of the input and output bitset.
		// Parameters:
		//		Stream1: A bitset with the value of the bits to puncture.
		//		Stream2: A bitset with the value of the bits to puncture.
		// Description:
		//		Returns a bitset with the values of the input bitset punctured with the Parity method.
		// Note:
		//		Prints the output bitset values if PRINT constant value is set to TRUE (Utils.h).
		//		Prints memory management and computing performance stats.
		static std::bitset<size> Puncture(std::bitset<size> stream1, std::bitset<size> stream2)
		{
			std::cout << "Bitwise Parity Puncturing" << std::endl;

			std::bitset<size> output = Utils::create_bitset_from_string<size>(std::string(size, '0'));

			long long check1 = Utils::milliseconds_now();

			for (int i = 0; i < size; i += 2) {
				output[i] = stream1[i];
				if (i + 1 < size) {
					output[i + 1] = stream2[i + 1];
				}
			}

			long long check2 = Utils::milliseconds_now();

			Utils::print_bitset(output);

			std::cout << "Size in bytes of the input1: " << sizeof(stream1) << std::endl;
			std::cout << "Size in bytes of the input2: " << sizeof(stream2) << std::endl;
			std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
			std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

			return output;
		}
	};
}
