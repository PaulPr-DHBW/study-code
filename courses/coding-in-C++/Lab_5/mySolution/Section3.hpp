#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

template <typename DATA>
class DRONE
{
private:
    std::vector<DATA> drone_data_vector;
    DATA data_vector_sum{};
    DATA data_vector_max{};
    double data_vector_av{};


    bool Status_Stream;
    bool motor_active;
    bool obstacle_sensor_active;
    bool GPS_lock;

    void set_vector_sum()
    {
        data_vector_sum = DATA{};

        for (const DATA& x : drone_data_vector)
        {
            data_vector_sum += x;
        }
    }

    void set_vector_max()
    {
        if (drone_data_vector.empty())
        {
            data_vector_max = DATA{};
            return;
        }

        data_vector_max = drone_data_vector[0];

        for (auto it = drone_data_vector.begin(); it != drone_data_vector.end(); ++it)
        {
            if (*it > data_vector_max)
            {
                data_vector_max = *it;
            }
        }
    }

    void set_vector_av()
    {
        data_vector_av = 0.0;

        if (!drone_data_vector.empty())
        {
            data_vector_av =
                static_cast<double>(data_vector_sum) /
                static_cast<double>(drone_data_vector.size());
        }
    }

    template <int N>
    void convert_array_to_vector(const DATA(&arr)[N])
    {
        for (int i = 0; i < N; i++)
        {
            drone_data_vector.push_back(arr[i]);
        }
    }

public:
    DRONE(const std::vector<DATA>& drone_data_init)
        : drone_data_vector(drone_data_init)
    {
        set_vector_sum();
        set_vector_max();
        set_vector_av();
    }

    template <int N>
    DRONE(const DATA(&arr)[N])
    {
        convert_array_to_vector(arr);
        set_vector_sum();
        set_vector_max();
        set_vector_av();
    }
    DRONE(bool motor_active_status, bool sensor_active_status, bool gps_lock_status) : 
        motor_active(motor_active_status), 
        obstacle_sensor_active(sensor_active_status), 
        GPS_lock(gps_lock_status)
    {
        Status_Stream = 1;
    }


    void report() const
    {
        if (!drone_data_vector.empty())
        {
            std::cout << "Drone Data Report:\n"
                << "Summe:   " << data_vector_sum << "\n"
                << "Max:     " << data_vector_max << "\n"
                << "Average: " << data_vector_av << "\n";
        }
    }
    bool status_stream_report()
    {
        int count = 0;
        if (motor_active)
        {
            count++;
        }
        if (GPS_lock)
        {
            count++;
        }
        if (obstacle_sensor_active)
        {
            count++;
        }

        if (count >=2)
        {
            return true;
        }
        return false;
    }

};