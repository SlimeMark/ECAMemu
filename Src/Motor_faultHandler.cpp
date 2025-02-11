#include "Motor_faultHandler.h"
#include <random>
#include <algorithm>

Motor_faultHandler::Motor_faultHandler() = default;

void Motor_faultHandler::fillMotorStats(int f_motorID, double f_temperature, double f_given_current, double f_current, int f_rpm, int f_ecd, bool f_ack)
{
    p_motor_stats.p_motorID = f_motorID;
    p_motor_stats.p_temperature = f_temperature;
    p_motor_stats.p_given_current = f_given_current;
    p_motor_stats.p_current = f_current;
    p_motor_stats.p_rpm = f_rpm;
    p_motor_stats.p_ecd = f_ecd;
    p_motor_stats.p_ack = f_ack;
}

Motor_faultHandler::motor_measure_t Motor_faultHandler::getMotorStats() const
{
    return p_motor_stats;
}

Motor_faultHandler::~Motor_faultHandler() = default;

int Motor_faultHandler::errGenerator()
{
    // Simulated motor data receive
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> temp(23, 100);
    std::uniform_real_distribution<> given_current(0, 10);
    std::uniform_real_distribution<> current(0, 10);
    std::uniform_int_distribution rpm(0, 10000);
    std::uniform_int_distribution ecd(-65535, 65535);
    std::uniform_int_distribution ack(0, 1);
    for (int i=1; i<5; i++)
    {
        fillMotorStats(i, temp(gen), given_current(gen), current(gen), rpm(gen), ecd(gen), ack(gen));
        int last_ecd = 0;
        if (getMotorStats().p_temperature > 50 && getMotorStats().p_temperature < 65)
        {
            return 10+i; // 1i CTRL MOTORi OVHT CAUT
        }
        if (getMotorStats().p_temperature >= 65)
        {
            return 20+i; // 2i CTRL MOTORi OVHT WARN
        }
        if (getMotorStats().p_current == 0 && getMotorStats().p_given_current != 0)
        {
            return 30+i; // 3i CTRL MOTORi CURRENT DISAGREE CAUT
        }
        if (getMotorStats().p_current > getMotorStats().p_given_current)
        {
            return 40+i; // 4i CTRL MOTORi CURRENT DISAGREE WARN
        }
        if (getMotorStats().p_current != 0 && getMotorStats().p_rpm == 0)
        {
            return 50+i; // 5i CTRL MOTORi BLOCK WARN
        }
        last_ecd = getMotorStats().p_ecd;
        if (getMotorStats().p_rpm != 0 && last_ecd == getMotorStats().p_ecd)
        {
            return 60+i; // 6i CTRL MOTORi ECD DISAGREE WARN
        }
        if (getMotorStats().p_ack == 0)
        {
            return 70+i; // 7i CTRL MOTORi OFFLINE WARN
        }
    }

    return 0;
}
