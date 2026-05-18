#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// Vorwärtsdeklaration
class inspection;

//-----------------------------------------------
//                  Interface
//-----------------------------------------------
class reportable
{
public:
    virtual void print_report() const = 0;
    virtual ~reportable() = default;
};

//-----------------------------------------------
//                  Product
//-----------------------------------------------
class Product : public reportable
{
private:
    int product_ID;
    std::string name;

    std::vector<inspection*> inspection_results;

protected:
    double weight;
    double temperature;
    bool visual_defect_status;

public:
    Product(std::string name, int product_ID, double weight, double temperature, bool visual_defect_status);

    int get_product_ID() const;
    std::string get_name() const;
    double get_weight() const;
    double get_temperature() const;
    bool get_visual_defect_status() const;

    void add_inspection_result(inspection& new_inspection);

    void print_report() const override;

    virtual double get_max_weight() const = 0;
    virtual double get_min_weight() const = 0;
    virtual double get_max_temp() const = 0;
    virtual double get_min_temp() const = 0;

    virtual ~Product() = default;
};

//-----------------------------------------------
//              Combustion Engine
//-----------------------------------------------
class combustion_engine : public Product
{
private:
    static constexpr double max_weight = 300.0;
    static constexpr double min_weight = 120.0;
    static constexpr double max_temp = 200.0;
    static constexpr double min_temp = 50.0;

public:
    combustion_engine(std::string name, int product_ID, double weight, double temperature, bool visual_defect_status);

    double get_max_weight() const override;
    double get_min_weight() const override;
    double get_max_temp() const override;
    double get_min_temp() const override;
};

//-----------------------------------------------
//              Electrical Engine
//-----------------------------------------------
class electrical_engine : public Product
{
private:
    double voltage;

    static constexpr double max_weight = 300.0;
    static constexpr double min_weight = 120.0;
    static constexpr double max_temp = 200.0;
    static constexpr double min_temp = 50.0;
    static constexpr double max_voltage = 800.0;
    static constexpr double min_voltage = 200.0;

public:
    electrical_engine(std::string name, int product_ID, double weight, double temperature, bool visual_defect_status, double voltage);

    double get_voltage() const;

    double get_max_weight() const override;
    double get_min_weight() const override;
    double get_max_temp() const override;
    double get_min_temp() const override;

    double get_max_voltage() const;
    double get_min_voltage() const;
};