#include "MatrixInterleaver.h"
#include "PermutationInterleaver.h"
#include "NscEncoder.h"
#include "RscEncoder.h"
#include "ParityPuncturing.h"
#include "VectorPuncturing.h"


#define INPUT_SIZE				4
#define INPUT_STRING			"1011"
//#define INPUT_SIZE				11
//#define INPUT_STRING			"00111100101"

#define BLOCK_NUMBER			2

#define PERMUTATION_VECTOR		"3142"
#define PUNCTURING_MATRIX		"110010110111"

int main()
{
	//--------------------------------------------------------------//
	//					Declaration of variables					//
	//--------------------------------------------------------------//
	// Creation of permutation vector
	std::string permutation_string(PERMUTATION_VECTOR);
	std::vector<short> permutation_vector;
	permutation_vector.reserve(permutation_string.size());

	for (int i = 0; i < permutation_string.size(); i++) {
		permutation_vector.push_back(permutation_string[i] - 48);
	}

	// Creation of puncturing bitset
	std::bitset<INPUT_SIZE * 3> puncturing_bitset = TurboCoder::Utils::create_bitset_from_string<INPUT_SIZE * 3>(PUNCTURING_MATRIX);
	
	// Creation of input bitset
	std::bitset<INPUT_SIZE> input = TurboCoder::Utils::create_bitset_from_string<INPUT_SIZE>(INPUT_STRING);


	//--------------------------------------------------------------//
	//					 Normal execution flow						//
	//--------------------------------------------------------------//
	std::bitset<INPUT_SIZE> encoder1 = TurboCoder::RSCEncoder<INPUT_SIZE, BLOCK_NUMBER>::Encode(input);
	std::bitset<INPUT_SIZE> interleaver = TurboCoder::MatrixInterleaver<INPUT_SIZE>::Interleave(input);
	std::bitset<INPUT_SIZE> encoder2 = TurboCoder::RSCEncoder<INPUT_SIZE, BLOCK_NUMBER>::Encode(interleaver);
	std::bitset<INPUT_SIZE> puncturing = TurboCoder::ParityPuncturing<INPUT_SIZE>::Puncture(encoder1, encoder2);

	std::bitset<INPUT_SIZE * 2> input_encoded_parity_puncturing(puncturing.to_string() + input.to_string());
	std::bitset<INPUT_SIZE * 2> input_encoded_parity_punturing_interleaver(puncturing.to_string() + interleaver.to_string());


	//--------------------------------------------------------------//
	//			  Alternatives to normal execution flow				//
	//--------------------------------------------------------------//
	// Alternative nsc encoder (Not used in turbo codes)
	std::bitset<INPUT_SIZE * 2> nsc_encoder1 = TurboCoder::NSCEncoder<INPUT_SIZE, BLOCK_NUMBER>::Encode(input);
	// Alternative purmutation interleaver method
	std::bitset<INPUT_SIZE> perm_interleaver = TurboCoder::PermutationInterleaver<INPUT_SIZE>::Interleave(input, permutation_vector);
	// Alternative without puncturing
	std::bitset<INPUT_SIZE * 3> input_encoded_without_puncturing(encoder2.to_string() + encoder1.to_string() + input.to_string());
	// Alternative vector punturing method
	std::bitset<INPUT_SIZE * 2> input_encoded_with_vector_puncturing = TurboCoder::VectorPuncturing<INPUT_SIZE * 3>::Puncture(input_encoded_without_puncturing, puncturing_bitset);

	system("PAUSE");
}