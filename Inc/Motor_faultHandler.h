#ifndef MOTOR_FAULTHANDLER_H
#define MOTOR_FAULTHANDLER_H


class Motor_faultHandler
{
    typedef struct
    {
        int p_motorID;
        double p_temperature;
        double p_given_current;
        double p_current;
        int p_rpm;
        int p_ecd;
        bool p_ack;
    }motor_measure_t;

    public:
        Motor_faultHandler();
        ~Motor_faultHandler();

        void fillMotorStats(int f_motorID, double f_temperature, double f_given_current, double f_current, int f_rpm, int f_ecd, bool f_ack);


        [[nodiscard]] motor_measure_t getMotorStats() const;
        int errGenerator();

    private:
        motor_measure_t p_motor_stats{};
};



#endif //MOTOR_FAULTHANDLER_H
