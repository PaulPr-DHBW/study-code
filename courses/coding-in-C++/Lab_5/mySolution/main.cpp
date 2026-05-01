//All Standards Libs
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

//Own Headers
#include "Section1.hpp"
#include "Section2.hpp"
#include "Section3.hpp"







int main(void)
{
	//Lets begin with Section 1:

	//--------- Task 1 ------------
	int task_1_a = 1;
	int task_1_b = 2;
	std::cout << "Variable a (int) vorher: " << task_1_a << std::endl;
	generic_swap(task_1_a, task_1_b);
	std::cout << "Variable a (int) nachher: " << task_1_a << std::endl << std::endl;

	std::string task_1_c = "Hallo";
	std::string task_1_d = "Hey";
	std::cout << "Variable a (string) vorher: " << task_1_c << std::endl;
	generic_swap(task_1_c, task_1_d);
	std::cout << "Variable a (string) nachher: " << task_1_c << std::endl << std::endl;

	//--------- Task 2 ------------
	int task_2_int_arr[5] = { 1,2,3,4,5 };
	double task_2_double_arr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	sensor_frame_printer(task_2_int_arr);
	sensor_frame_printer(task_2_double_arr);

	//--------- Task 3 ------------
	std::cout << std::setprecision(2) << weakest_signal_detector(task_2_double_arr) << std::endl;

	//--------- Task 4 ------------
	tag_composer("Channel", "Priority", "motor_temp", 2);


	std::cout << "\n\n\n";

	// Lets begin with Section 2:

	//--------- Task 6 ------------
	std::vector<int> vector_sec_2_6 = { 42, 17, 42, 5, 99, 17, 63, 12 };
	const int sec_2_searched_value = 63;
	sort_inspect_data(vector_sec_2_6, sec_2_searched_value); //


	//--------- Task 7 ------------
	std::vector<int> vector_sec_2_7 = { 7, -1, 13, -1, 21, 21, 8, -1, 8 };
	noise_cleanup(vector_sec_2_7);

	//--------- Task 8 ------------
	iterator_walk(vector_sec_2_7);



	std::cout << "\n\n\n";

	//Lets begin with Section 3

	//--------- PART A----------
	DRONE mydrone_a(vector_sec_2_6);
	mydrone_a.report();

	//--------- PART B ---------
	DRONE mydrone_b(task_2_double_arr);
	mydrone_b.report();

	//--------- PART C ---------
	bool Motor = true;
	bool GPS = true;
	bool Sensor = true;
	DRONE<bool> mydrone_c(Motor, Sensor, GPS);
	mydrone_c.status_stream_report();







	return 0;
}