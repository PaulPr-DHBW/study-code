#include "Product.hpp"
#include "Inspection.hpp"
#include "Pipeline.hpp"

#include <iostream>
#include <vector>

int main()
{
    // Inspections erstellen
    weight_inspection weight_check("Weight Check");
    temperature_inspection temperature_check("Temperature Test");
    visual_inspection visual_check("Visual Inspection");

    // Pipeline erstellen
    quality_control_pipeline pipeline("Engine Quality Control");

    pipeline.add_inspection(weight_check);
    pipeline.add_inspection(temperature_check);
    pipeline.add_inspection(visual_check);

    // Produkte erstellen
    combustion_engine combustion1("Combustion Engine 1", 1, 180.0, 90.0, false);
    combustion_engine combustion2("Combustion Engine 2", 2, 350.0, 100.0, false);

    electrical_engine electric1("Electric Engine 1", 3, 220.0, 80.0, false, 400.0);
    electrical_engine electric2("Electric Engine 2", 4, 250.0, 250.0, true, 700.0);

    // Alle Produkte in einem gemeinsamen Array speichern
    std::vector<Product*> products;

    products.push_back(&combustion1);
    products.push_back(&combustion2);
    products.push_back(&electric1);
    products.push_back(&electric2);

    // Pipeline auf jedes Produkt anwenden
    for (Product* product : products)
    {
        pipeline.run(*product);
        std::cout << "\n-----------------------------\n\n";
    }

    // Am Ende Reports der Inspection-Arten ausgeben
    std::cout << "\n===== Inspection Reports =====\n\n";

    weight_check.print_report();
    temperature_check.print_report();
    visual_check.print_report();

    return 0;
}