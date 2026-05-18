#include "Pipeline.hpp"
#include "Inspection.hpp"
#include "Product.hpp"

#include <iostream>
#include <string>
#include <vector>

quality_control_pipeline::quality_control_pipeline(std::string name)
    : name(name)
{
}

void quality_control_pipeline::add_inspection(inspection& new_inspection)
{
    inspection_vector.push_back(&new_inspection);
}

void quality_control_pipeline::run(Product& current_product)
{
    for (auto it = inspection_vector.begin(); it != inspection_vector.end(); ++it)
    {
        (*it)->run_inspection(&current_product);
        current_product.add_inspection_result(**it);
    }

    current_product.print_report();
}