#ifndef MOTOR_FAULTHANDLER_H
#define MOTOR_FAULTHANDLER_H

#define CTRL_MOTOR1_OVHT_CAUT 111
#define CTRL_MOTOR2_OVHT_CAUT 112
#define CTRL_MOTOR3_OVHT_CAUT 113
#define CTRL_MOTOR4_OVHT_CAUT 114
#define CTRL_MOTOR1_OVHT_WARN 221
#define CTRL_MOTOR2_OVHT_WARN 222
#define CTRL_MOTOR3_OVHT_WARN 223
#define CTRL_MOTOR4_OVHT_WARN 224
#define CTRL_MOTOR1_CURRENT_DISAGREE_CAUT 131
#define CTRL_MOTOR2_CURRENT_DISAGREE_CAUT 132
#define CTRL_MOTOR3_CURRENT_DISAGREE_CAUT 133
#define CTRL_MOTOR4_CURRENT_DISAGREE_CAUT 134
#define CTRL_MOTOR1_CURRENT_DISAGREE_WARN 241
#define CTRL_MOTOR2_CURRENT_DISAGREE_WARN 242
#define CTRL_MOTOR3_CURRENT_DISAGREE_WARN 243
#define CTRL_MOTOR4_CURRENT_DISAGREE_WARN 244
#define CTRL_MOTOR1_BLOCK_WARN 251
#define CTRL_MOTOR2_BLOCK_WARN 252
#define CTRL_MOTOR3_BLOCK_WARN 253
#define CTRL_MOTOR4_BLOCK_WARN 254
#define CTRL_MOTOR1_ECD_DISAGREE_WARN 261
#define CTRL_MOTOR2_ECD_DISAGREE_WARN 262
#define CTRL_MOTOR3_ECD_DISAGREE_WARN 263
#define CTRL_MOTOR4_ECD_DISAGREE_WARN 264
#define CTRL_MOTOR1_OFFLINE_WARN 271
#define CTRL_MOTOR2_OFFLINE_WARN 272
#define CTRL_MOTOR3_OFFLINE_WARN 273
#define CTRL_MOTOR4_OFFLINE_WARN 274


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
        int errGenerator(int i);
        int instructProvider(int errID);

    private:
        motor_measure_t p_motor_stats{};
};



#endif //MOTOR_FAULTHANDLER_H
