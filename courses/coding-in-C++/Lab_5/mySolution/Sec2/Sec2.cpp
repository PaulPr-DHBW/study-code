#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void print_vector(std::vector<int> const& output_v);
void search_value_vector(std::vector<int>& searching_v, const int searched_value);
void noise_cleanup(std::vector<int>& cleanup_v);
void print_explicit(std::vector<int> printing_v);


int main (void)
{
    std::vector<int> main_v = {42, 17, 42, 5 , 99, 17, 63, 12};

    //  Printing the Vector main_v
    print_vector(main_v);

    //  Sort the Vecotr main_c and print it
    std::sort(main_v.begin(), main_v.end());
    print_vector(main_v);

    //Search for 63
    const int searched_number = 63;
    search_value_vector(main_v, searched_number);

    std::vector<int> main_v_2 = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    noise_cleanup(main_v_2);

    return 0;
}

void print_vector(std::vector<int> const& output_v)
{
    std::cout << "Printing Vector: ";
    for(int x : output_v)
    {
        std::cout << x << "  ";
    }
    std::cout << std::endl;
}
void search_value_vector(std::vector<int>& searching_v, const int searched_value)
{
    std::vector<int>::iterator it;
    it = std::find(searching_v.begin(), searching_v.end(), searched_value);

    if (it != searching_v.end())
    {
        std::cout<< "Value exits" << std::endl;
        return;
    }
    std::cout<< "Value doesnt exits" << std::endl;

}
void noise_cleanup(std::vector<int>& cleanup_v)
{
    //  Replacing all -1 with 0s while counting 8s
    int count = 0;
    std::vector<int>::iterator it;

    for (it = cleanup_v.begin(); it < cleanup_v.end(); it++)
    {
        if (*it == -1)
        {
            *it = 0;
        }
        if (*it == 8)
        {
            count++;
        }   
    }
    print_vector(cleanup_v);

    //  Reversing the vector
    std::reverse(cleanup_v.begin(), cleanup_v.end());
    print_vector(cleanup_v);
}
void print_explicit(std::vector<int> printing_v)
{
    std::vector<int>::iterator it;

    for (it = printing_v.begin(); it < printing_v.end(); it++)
    {
       std::cout << *it << "  " << std::endl;  
    }
}