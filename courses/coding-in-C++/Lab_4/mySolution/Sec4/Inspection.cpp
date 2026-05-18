#include "Inspection.hpp"

#include <iostream>
#include <iomanip>
#include <string>

//-----------------------------------------------
//                  Inspections
//-----------------------------------------------
inspection::inspection(std::string name)
    : name(name)
{
}

void inspection::print_report() const
{
    std::cout << "Inspection Statistics for: " << name << "\n";
    std::cout << "Last Result: "
        << (last_result ? "Passed" : "Failed") << std::endl;

    std::cout << "Successfull Inspections: "
        << successfull_inspections << std::endl;

    std::cout << "Total Inspections: "
        << total_checks << std::endl;

    double ratio = 0.0;

    if (total_checks > 0)
    {
        ratio = static_cast<double>(successfull_inspections) / total_checks * 100.0;
    }

    std::cout << "Ratio: "
        << std::fixed << std::setprecision(2)
        << ratio << "%\n\n";
}

std::string inspection::get_name() const
{
    return name;
}

bool inspection::get_inspection_passed() const
{
    return inspection_passed;
}

//-----------------------------------------------
//              Weight Inspection
//-----------------------------------------------
weight_inspection::weight_inspection(std::string name)
    : inspection(name)
{
}

void weight_inspection::run_inspection(Product* test_object)
{
    total_checks++;

    if (test_object->get_weight() <= test_object->get_max_weight() &&
        test_object->get_weight() >= test_object->get_min_weight())
    {
        successfull_inspections++;
        last_result = true;
        inspection_passed = true;
        return;
    }

    last_result = false;
    inspection_passed = false;
}

//-----------------------------------------------
//              Temperature Inspection
//-----------------------------------------------
temperature_inspection::temperature_inspection(std::string name)
    : inspection(name)
{
}

void temperature_inspection::run_inspection(Product* test_object)
{
    total_checks++;

    if (test_object->get_temperature() <= test_object->get_max_temp() &&
        test_object->get_temperature() >= test_object->get_min_temp())
    {
        successfull_inspections++;
        last_result = true;
        inspection_passed = true;
        return;
    }

    last_result = false;
    inspection_passed = false;
}

//-----------------------------------------------
//              Visual Inspection
//-----------------------------------------------
visual_inspection::visual_inspection(std::string name)
    : inspection(name)
{
}

void visual_inspection::run_inspection(Product* test_object)
{
    total_checks++;

    if (test_object->get_visual_defect_status())
    {
        last_result = false;
        inspection_passed = false;
        return;
    }

    successfull_inspections++;
    last_result = true;
    inspection_passed = true;
}