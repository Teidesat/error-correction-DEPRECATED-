#pragma once

#define PRINT true							// When PRINT value is TRUE shows in the console the value 
											//	of the bitset after every operation
#define INTERLEAVER_PADDING '0'				// The bit value that uses into interleavers when the input 
											//	is smaller than the required output
#define ENCODER_INITIAL_CONTENT  "0"		// The content used to initialize the blocks of the encoders
											//  at the beginning of every encodign process

#include <iostream>
#include <bitset>
#include <vector>
#include <Windows.h>

namespace TurboCoder {
	class Utils
	{
	public:
		// Static Function
		// Description: 
		//		Returns the actual time into 8 bytes (Uses Windows Library).
		static long long milliseconds_now() {
			static LARGE_INTEGER s_frequency;
			static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
			if (s_use_qpc) {
				LARGE_INTEGER now;
				QueryPerformanceCounter(&now);
				return (1000LL * now.QuadPart) / s_frequency.QuadPart;
			}
			else {
				return GetTickCount();
			}
		}

		// Static Function
		// Template parameters:
		//		Size: Length of the resulting bitset.
		// Parameters:
		//		Input: A string with the value of the bits.
		// Description:
		//		Returns a bitset with the values of the input string. 
		// Note:
		//		If the input string is bigger than the resulting bitset, will take the first characters to fill the bitset.
		//		If the input string is smaller than the resulting bitset, will fill the bitset with 0.
		template<int size>
		static std::bitset<size> create_bitset_from_string(std::string input)
		{
			std::string input_string(input);
			input_string = input_string.substr(0, size);			

			for (int i = input_string.length(); i < size; i++) {
				input_string.append("0");
			}

			std::reverse(input_string.begin(), input_string.end());

			return std::bitset<size>(input_string);
		}

		// Static Function
		// Template parameters:
		//		Size: Length of the input bitset.
		// Parameters:
		//		Input: A bitset with the value of the bits.
		// Description:
		//		Returns a string with the values of the input bitset.
		template<int size>
		static std::string bitset_to_string(std::bitset<size> input)
		{
			std::string input_string = input.to_string();
			std::reverse(input_string.begin(), input_string.end());
			return input_string;
		}

		// Static Function
		// Template parameters:
		//		Size: Length of the input bitset.
		// Parameters:
		//		Input: A bitset with the value of the bits.
		// Description:
		//		Prints the values of the bits from the input bitset.
		template<int size>
		static void print_bitset(std::bitset<size> input)
		{
#if PRINT == true
			std::cout << input << std::endl;
#endif 
		}
	};
}