#include <iostream>
#include <string>

//==== Lab 5 - Sec 1 Payload Switch ====
template <typename T>
void generic_swap(T a, T b)
{
    std::cout   << "Before Swapping:\n"
                << "a: " << a << std::endl
                << "b: " << b << std::endl;

    T temp = a;
    a = b;
    b = temp;

    std::cout   << "After Swapping:\n"
                << "a: " << a << std::endl
                << "b: " << b << std::endl;
}
//Why is a template better? You use one logic for different types, saving time and providing a better overview of the code

//==== Lab 5 - Sec 1 Sensor Frame Printer ====
template <typename T, int N>
void print_sensor_frame(T (&arr)[N])
{
    std:: cout << "[" ;
    for (int i = 0; i < N; i++)
    {
        std:: cout << ", "<< arr[i];
    }
    std:: cout << "]" << std::endl;    
}

//==== Lab 5 - Sec 1 Weakest Signal Detector ====
template <typename T, int N>
T min_measure_frame(T (&arr)[N])
{
    T min = arr[0];
    
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        
    }
    
    return min;
}

//==== Lab 5 - Sec 1 Telematry Tag Composer ====
template <typename T, typename U>
void tag_composer(std::string label_1, std::string label_2, T value_1, U value_2)
{
    std::cout   << label_1 << ": "
                << value_1
                << " | "
                << label_2 << ": "
                << value_2 << std::endl;
}

//==== Lab 5 - Sec 1 Fixed-Size Packet Buffer ====
template <typename O, int L>
void fixed_buffer(O (&arr)[L])
{
    std:: cout << "[" ;
    for (int i = 0; i < L; i++)
    {
        std:: cout << ", "<< arr[i];
    }
    std:: cout << "]" << std::endl;    
}




//==== Main Function====
int main(void)
{
    //  Test Task 1 - Swap
    int exmpl_a = 1;
    int exmpl_b = 2;
    generic_swap(exmpl_a, exmpl_b);

    //  Test Task 2 - Frame
    int i_arr[5] = {1,2,3,4,5};
    double d_arr[5] = {1.0,2.3,3.4};

    //  Test Task 3 - Weakest
    min_measure_frame(i_arr);

    //  Test Task 4 - Tag Composer
    tag_composer("Motor", "ID", 1.4, 3);

    return 0;
}