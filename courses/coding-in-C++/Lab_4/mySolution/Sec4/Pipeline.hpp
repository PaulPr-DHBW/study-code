#pragma once

#include <string>
#include <vector>

class Product;
class inspection;

class quality_control_pipeline
{
private:
    std::vector<inspection*> inspection_vector;
    std::string name;

public:
    quality_control_pipeline(std::string name);

    void add_inspection(inspection& new_inspection);

    void run(Product& current_product);

    ~quality_control_pipeline() = default;
};