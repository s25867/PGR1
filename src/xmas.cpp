#include <string>
#include <iostream>

int _tmain(int argc, char* argv[])
{
	int stars = 1;

	//size is all you need to change, to automatically
	//change the size of the stump

	//size of tree in height
	int size = 10;

	int stumpHeight = size / 3;
	int stumpWidth = size / 2;

	for( int total = size; total > 0; --total )
	{
		//control the amount of spaces
		for( int i = ( total - 1 ); i > 0; --i )
			std::cout << " ";

		//control the amount of stars
		for( int j = 0; j < stars ; ++j )
			std::cout << "*";

		//next row needs 2 extra stars
		stars += 2;

		std::cout << '\n';
	}


	//create the stump
	for( int i = 0; i < stumpHeight; ++i )
	{
		//spaces to the center of the tree
		//so that the stump is centered
		for( int j = 0; j < ( size - ( stumpWidth - ( stumpWidth / 2 ) ) ); ++j )
			std::cout << " ";

		for( int k = 0; k < stumpWidth; ++k )
			std::cout << "*";

		std::cout << '\n';
	}

	return 0;
}
