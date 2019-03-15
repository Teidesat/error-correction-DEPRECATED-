#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size>
	class VectorPuncturing
	{
	public:
		// Static Function
		// Template parameters:
		//		Size: Length of the input bitset.
		// Parameters:
		//		Stream1: A bitset with the value of the bits to puncture.
		//		Puncturing_vector: A vector with index of the bits to take into puncture.
		// Description:
		//		Returns a bitset with the values of the input bitset punctured with the Vector method.
		// Note:
		//		Prints the output bitset values if PRINT constant value is set to TRUE (Utils.h).
		//		Prints memory management and computing performance stats.
		static std::bitset<size / 3 * 2> Puncture(std::bitset<size> stream1, std::bitset<size> punturing_vector)
		{
			std::cout << "Bitwise Vector Puncturing" << std::endl;

			std::bitset<size / 3 * 2> output = Utils::create_bitset_from_string<size / 3 * 2>(std::string(size / 3 * 2, '0'));
			int counter = 0;

			long long check1 = Utils::milliseconds_now();

			for (int i = 0; i < size; i++) {
				if (punturing_vector[i]) {
					output[counter] = stream1[i];
					counter++;
				}
			}

			long long check2 = Utils::milliseconds_now();

			Utils::print_bitset(output);

			std::cout << "Size in bytes of the input: " << sizeof(stream1) << std::endl;
			std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
			std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

			return output;
		}
	};
}
