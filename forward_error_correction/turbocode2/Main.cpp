#include <Windows.h>
#include <bitset>
#include <iostream>
#include <vector>

#include "MatrixInterleaver.h"
#include "PermutationInterleaver.h"
#include "NscEncoder.h"
#include "RscEncoder.h"
#include "ParityPuncturing.h"
#include "VectorPuncturing.h"


#define INPUT_SIZE				4
#define INPUT_STRING			"1011"

#define BLOCK_NUMBER			4
#define INITIAL_CONTENT			"0000000000000000"

#define INTERLEAVER_ROWS		2
#define INTERLEAVER_COLUMNS		2

#define PERMUTATION_VECTOR		"3142"

#define PUNTURING_MATRIX		"1100,1011,0111"


#define PRINT					1

long long milliseconds_now_l() {
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

template <int size, int blocks>
std::bitset<size*2> bitwiseNSC(std::bitset<size> input)
{
	std::cout << "Bitwise NSC Encoder" << std::endl;

	long long check1 = milliseconds_now_l();

	std::bitset<size*2> output;
	//std::bitset<blocks> k = std::bitset<blocks>(std::string(INITIAL_CONTENT));
	std::bitset<blocks> k = std::bitset<blocks>(std::string(blocks, '0'));
	
	long long check2 = milliseconds_now_l();

	for (int i = 0; i < size; i++) {
		output[i * 2] = (input[i] + k[0]) % 2;

		int sum = input[i];
		for (int j = 0; j < blocks; j++) {
			sum += k[j];
		}
		output[i * 2 + 1] = sum % 2;

		for (int j = 0; j < blocks - 1; j++)
		{
			k[j] = k[j + 1];
		}
		k[blocks - 1] = input[i];
	}

	long long check3 = milliseconds_now_l();

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

template <int size, int blocks>
std::bitset<size> bitwiseRSC(std::bitset<size> input)
{
	std::cout << "Bitwise RSC Encoder" << std::endl;

	long long check1 = milliseconds_now_l();

	std::bitset<size> output;
	//std::bitset<blocks> k = std::bitset<blocks>(std::string(INITIAL_CONTENT));
	std::bitset<blocks> k = std::bitset<blocks>(std::string(blocks, '0'));

	long long check2 = milliseconds_now_l();
	
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

	long long check3 = milliseconds_now_l();

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


template<int size, int rows, int columns>
std::bitset<size> bitwiseMatrixInterleaver(std::bitset<size> input)
{
	std::cout << "Bitwise Matrix Interleaver" << std::endl;

	std::bitset<size> output("");

	long long check1 = milliseconds_now_l();

	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			if (j * rows + i < size) {
				output[(size - 1) - (i * rows + j)] = input[(size - 1) - (j * rows + i)];
			}
		}
	}

	long long check2 = milliseconds_now_l();

#if PRINT == 1
	std::cout << output << std::endl;
#endif 

	std::cout << "Size in bytes of the input: " << sizeof(input) << std::endl;
	std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
	std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

	return output;
}

template<int size>
std::bitset<size> bitwisePermutationInterleaver(std::bitset<size> input, std::vector<short> permutation)
{
	std::cout << "Bitwise Permutation Interleaver" << std::endl;

	std::bitset<size> output("");

	long long check1 = milliseconds_now_l();

	for (int i = 0; i < size; i++) {
		output[i] = input[permutation[i]];
	}

	long long check2 = milliseconds_now_l();

#if PRINT == 1
	std::cout << output << std::endl;
#endif 

	std::cout << "Size in bytes of the input: " << sizeof(input) << std::endl;
	std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
	std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

	return output;
}

template<int size>
std::bitset<size> parityPunturing(std::bitset<size> stream1, std::bitset<size> stream2)
{
	std::cout << "Bitwise Parity Puncturing" << std::endl;

	std::bitset<size> output("");

	long long check1 = milliseconds_now_l();

	for (int i = 0; i < size; i+=2) {
		output[i] = stream1[i];
		if (i + 1 < size) {
			output[i + 1] = stream2[i + 1];
		}		
	}

	long long check2 = milliseconds_now_l();

#if PRINT == 1
	std::cout << output << std::endl;
#endif 

	std::cout << "Size in bytes of the input1: " << sizeof(stream1) << std::endl;
	std::cout << "Size in bytes of the input2: " << sizeof(stream2) << std::endl;
	std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
	std::cout << "Computation time(ms): " << check2 - check1 << std::endl;
	
	return output;
}

template<int size, int output_size>
std::bitset<output_size> vectorPunturing(std::bitset<size> stream1, std::bitset<size> punturingVector)
{
	std::cout << "Bitwise Vector Puncturing" << std::endl;

	std::bitset<output_size> output;
	int counter = 0;

	long long check1 = milliseconds_now_l();

	for (int i = 0; i < size; i++) {
		if (punturingVector.test(i)) {
			output[counter] = stream1[i];
			counter++;
		}
	}

	long long check2 = milliseconds_now_l();

#if PRINT == 1
	std::cout << output << std::endl;
#endif 

	std::cout << "Size in bytes of the input: " << sizeof(stream1) << std::endl;
	std::cout << "Size in bytes of the output: " << sizeof(output) << std::endl;
	std::cout << "Computation time(ms): " << check2 - check1 << std::endl;

	return output;
}

int main()
{
	std::bitset<INPUT_SIZE> input(INPUT_STRING);
	std::string permutation(PERMUTATION_VECTOR);
	std::vector<short> permutation_vector;

	permutation.reserve(permutation.size());

	for (int i = 0; i < permutation.size(); i++) {
		permutation_vector.push_back(permutation[i] - 48);
	}

	//std::bitset<OUTPUT_SIZE> encoder1 = bitwiseNSC<INPUT_SIZE, BLOCK_NUMBER>(input);							// ENCODER V1 FAIL?
	//std::bitset<INPUT_SIZE> encoder1 = bitwiseRSC<INPUT_SIZE, BLOCK_NUMBER>(input);									// ENCODER RSC OK?

	//std::bitset<INPUT_SIZE> interleaver = bitwiseMatrixInterleaver<INPUT_SIZE, INTERLEAVER_ROWS, INTERLEAVER_COLUMNS>(input);
	//std::bitset<INPUT_SIZE> interleaver = bitwisePermutationInterleaver<INPUT_SIZE>(input, permutation_vector);	

	//std::bitset<INPUT_SIZE*2> encoder2 = bitwiseNSC<INPUT_SIZE, BLOCK_NUMBER>(interleaver);					// ENCODER V1 FAIL?
	//std::bitset<INPUT_SIZE> encoder2 = bitwiseRSC<INPUT_SIZE, BLOCK_NUMBER>(interleaver);							// ENCODER RSC OK?

	//std::bitset<INPUT_SIZE*2> puncturing = parityPunturing<INPUT_SIZE*2>(encoder1, encoder2);						// PUNTURING FOR V1 FAIL?
	//std::bitset<INPUT_SIZE> puncturing = parityPunturing<INPUT_SIZE>(encoder1, encoder2);							// PUNTURING RSC OK?

	//std::bitset<INPUT_SIZE*2> input_encoded_v1(puncturing.to_string() + input.to_string());							// TURBO CODE V1 RATIO 1/2 FAIL?
	//std::bitset<INPUT_SIZE*3> input_encoded_np(encoder2.to_string() + encoder1.to_string() + input.to_string());	// TURBO CODE RATIO 1/3 OK?
	//std::bitset<INPUT_SIZE*2> input_encoded_wp(puncturing.to_string() + input.to_string());							// TURBO CODE RATIO 1/2 OK?

	//int num = std::bitset<INPUT_SIZE>(PUNTURING_VECTOR).count();
	//std::bitset<INPUT_SIZE> puncturing2 = vectorPunturing<INPUT_SIZE, 2>(encoder1, std::bitset<INPUT_SIZE>(PUNTURING_VECTOR));
	//std::bitset<INPUT_SIZE> puncturing2 = vectorPunturing<INPUT_SIZE, 2>(encoder2, std::bitset<INPUT_SIZE>(PUNTURING_VECTOR));


	std::bitset<INPUT_SIZE> encoder1 = TurboCoder::RSCEncoder<INPUT_SIZE, BLOCK_NUMBER>::Encode(input);
	std::bitset<INPUT_SIZE> interleaver = TurboCoder::MatrixInterleaver<INPUT_SIZE, INTERLEAVER_ROWS, INTERLEAVER_COLUMNS>::Interleave(input);
	std::bitset<INPUT_SIZE> encoder2 = TurboCoder::RSCEncoder<INPUT_SIZE, BLOCK_NUMBER>::Encode(interleaver);
	std::bitset<INPUT_SIZE> puncturing = TurboCoder::ParityPuncturing<INPUT_SIZE>::Punture(encoder1, encoder2);
	std::bitset<INPUT_SIZE * 3> input_encoded_np(encoder2.to_string() + encoder1.to_string() + input.to_string());
	std::bitset<INPUT_SIZE * 2> input_encoded_wp(puncturing.to_string() + input.to_string());

	system("PAUSE");
}