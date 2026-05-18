#include "Product.hpp"
#include "Inspection.hpp"

#include <iostream>
#include <string>
#include <vector>

//-----------------------------------------------
//                  Product
//-----------------------------------------------
Product::Product(std::string name, int product_ID, double weight, double temperature, bool visual_defect_status)
    : product_ID(product_ID),
    name(name),
    weight(weight),
    temperature(temperature),
    visual_defect_status(visual_defect_status)
{
}

int Product::get_product_ID() const
{
    return product_ID;
}

std::string Product::get_name() const
{
    return name;
}

double Product::get_weight() const
{
    return weight;
}

double Product::get_temperature() const
{
    return temperature;
}

bool Product::get_visual_defect_status() const
{
    return visual_defect_status;
}

void Product::add_inspection_result(inspection& new_inspection)
{
    inspection_results.push_back(&new_inspection);
}

void Product::print_report() const
{
    bool total_pass = true;

    std::cout << "Report for: " << get_name() << ":\n\n";

    for (auto it = inspection_results.begin(); it != inspection_results.end(); ++it)
    {
        if (!(*it)->get_inspection_passed())
        {
            total_pass = false;
        }

        std::cout << "- " << (*it)->get_name() << ": "
            << (((*it)->get_inspection_passed()) ? "Passed" : "Failed")
            << std::endl;
    }

    std::cout << "\nTotal Pass: "
        << (total_pass ? "Passed" : "Failed")
        << std::endl;
}

//-----------------------------------------------
//              Combustion Engine
//-----------------------------------------------
combustion_engine::combustion_engine(std::string name, int product_ID, double weight, double temperature, bool visual_defect_status)
    : Product(name, product_ID, weight, temperature, visual_defect_status)
{
}

double combustion_engine::get_max_weight() const
{
    return max_weight;
}

double combustion_engine::get_min_weight() const
{
    return min_weight;
}

double combustion_engine::get_max_temp() const
{
    return max_temp;
}

double combustion_engine::get_min_temp() const
{
    return min_temp;
}

//-----------------------------------------------
//              Electrical Engine
//-----------------------------------------------
electrical_engine::electrical_engine(std::string name, int product_ID, double weight, double temperature, bool visual_defect_status, double voltage)
    : Product(name, product_ID, weight, temperature, visual_defect_status),
    voltage(voltage)
{
}

double electrical_engine::get_voltage() const
{
    return voltage;
}

double electrical_engine::get_max_weight() const
{
    return max_weight;
}

double electrical_engine::get_min_weight() const
{
    return min_weight;
}

double electrical_engine::get_max_temp() const
{
    return max_temp;
}

double electrical_engine::get_min_temp() const
{
    return min_temp;
}

double electrical_engine::get_max_voltage() const
{
    return max_voltage;
}

double electrical_engine::get_min_voltage() const
{
    return min_voltage;
}