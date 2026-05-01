#ifndef SECTION_1_HPP
#define SECTION_1_HPP
#include <iostream>
#include <string>


//-------------------------
// Tast 1 - Payload Swtich
//-------------------------
template <typename T>
void generic_swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


//------------------------
// Task 2 - Sensor Frame Printer
//------------------------
template <typename T, int N>
void sensor_frame_printer(T const (&arr)[N])
{
	std::cout << "Starting to print Sensor Frame:" << std::endl;

	for (int i = 0; i < N; i++)
	{

		std::cout << std::setprecision(2) << arr[i] << " ";
	}

	std::cout << std::endl;
}


//------------------------
// Task 3 - Weakest Signal Detector
//------------------------
template <typename T, int N>
T weakest_signal_detector(T const (&arr)[N])
{
	T min = arr[0]; //Setting min for the frist Element 

	for (T x : arr)
	{
		if (x < min)
		{
			min = x;
		}
	}

	return min;
}

//------------------------
// Task 4 - Telemetry Tag Composer
//------------------------
template <typename T, typename U>
void tag_composer(std::string label_1, std::string label_2, T value_1, U value_2)
{
	std::cout << label_1 << ": "
		<< value_1
		<< "	|	"
		<< label_2 << ": "
		<< value_2
		<< std::endl;
}

//------------------------
// Task 5
// A size parameter is no longer needed, because of the template definition int N
// Call by Value also write into this template Paramter which then functions as a Variable
//------------------------

#endif // !SECTION_1_HPP



