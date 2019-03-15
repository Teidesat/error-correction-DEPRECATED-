#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size>
	class MatrixInterleaver 
	{
	public:
		// Static Function
		// Template parameters:
		//		Size: Length of the input and output bitset.
		// Parameters:
		//		Input: A bitset with the value of the bits to interleave.
		// Description:
		//		Returns a bitset with the values of the input bitset interleaved by the Matrix method.
		// Note:
		//		Prints the output bitset values if PRINT constant value is set to TRUE (Utils.h).
		//		Prints memory management and computing performance stats.
		static std::bitset<size> Interleave(std::bitset<size> input)
		{
			std::cout << "Bitwise Matrix Interleaver" << std::endl;

			std::bitset<size> output = Utils::create_bitset_from_string<size>(std::string(size, INTERLEAVER_PADDING));

			long long check1 = Utils::milliseconds_now();

			int columns = std::sqrt(size);
			int rows = columns;
			
			for (int i = 0; i < columns; i++) {
				for (int j = 0; j < rows; j++) {
					if (j * columns + i < size) {
						output[(i * rows + j)] = input[(j * columns + i)];
					}
				}
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
