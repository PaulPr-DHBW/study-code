#pragma once

#include "Product.hpp"

#include <iostream>
#include <iomanip>
#include <string>

//-----------------------------------------------
//                  Inspections
//-----------------------------------------------
class inspection : public reportable
{
protected:
    bool inspection_passed = false;
    std::string name;

    bool last_result = false;
    int successfull_inspections = 0;
    int total_checks = 0;

public:
    inspection(std::string name);

    virtual void run_inspection(Product* test_object) = 0;
    void print_report() const override;

    std::string get_name() const;
    bool get_inspection_passed() const;

    virtual ~inspection() = default;
};

//-----------------------------------------------
//              Weight Inspection
//-----------------------------------------------
class weight_inspection : public inspection
{
public:
    weight_inspection(std::string name);
    void run_inspection(Product* test_object) override;
};

//-----------------------------------------------
//              Temperature Inspection
//-----------------------------------------------
class temperature_inspection : public inspection
{
public:
    temperature_inspection(std::string name);
    void run_inspection(Product* test_object) override;
};

//-----------------------------------------------
//              Visual Inspection
//-----------------------------------------------
class visual_inspection : public inspection
{
public:
    visual_inspection(std::string name);
    void run_inspection(Product* test_object) override;
};