#pragma once

#include "Utils.h"

namespace TurboCoder {
	template<int size, int blocks>
	class RSCEncoder
	{
	public:
		static std::bitset<size> Encode(std::bitset<size> input)
		{
			std::cout << "Bitwise RSC Encoder" << std::endl;

			long long check1 = milliseconds_now();

			std::bitset<size> output;
			//std::bitset<blocks> k = std::bitset<blocks>(std::string(INITIAL_CONTENT));
			std::bitset<blocks> k = std::bitset<blocks>(std::string(blocks, '0'));

			long long check2 = milliseconds_now();

			for (int i = 0; i < size; i++) {
				int sum = 0;
				for (int j = 0; j < blocks; j++) {
					sum += k[j];
				}

				output[i] = ((input[i] + (sum % 2)) + k[0]) % 2;

				for (int j = 0; j < blocks - 1; j++)
				{
					k[j] = k[j + 1];
				}
				k[blocks - 1] = (input[i] + (sum % 2)) % 2;
			}

			long long check3 = milliseconds_now();

#if PRINT == 1
			std::cout << output << std::endl;
#endif 

			std::cout << "Size in bytes of the input: " << sizeof(input) << std::endl;
			std::cout << "Size in bytes of the blocks: " << sizeof(k) << std::endl;
			std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
			std::cout << "Declaration time(ms): " << check2 - check1 << std::endl;
			std::cout << "Computation time(ms): " << check3 - check2 << std::endl;

			return output;
		}
	};
}