#include <iostream>
#include <Motor_faultHandler.h>
#include <thread>

#define CTRL_MOTOR1_OVHT_CAUT 11
#define CTRL_MOTOR2_OVHT_CAUT 12
#define CTRL_MOTOR3_OVHT_CAUT 13
#define CTRL_MOTOR4_OVHT_CAUT 14
#define CTRL_MOTOR1_OVHT_WARN 21
#define CTRL_MOTOR2_OVHT_WARN 22
#define CTRL_MOTOR3_OVHT_WARN 23
#define CTRL_MOTOR4_OVHT_WARN 24
#define CTRL_MOTOR1_CURRENT_DISAGREE_CAUT 31
#define CTRL_MOTOR2_CURRENT_DISAGREE_CAUT 32
#define CTRL_MOTOR3_CURRENT_DISAGREE_CAUT 33
#define CTRL_MOTOR4_CURRENT_DISAGREE_CAUT 34
#define CTRL_MOTOR1_CURRENT_DISAGREE_WARN 41
#define CTRL_MOTOR2_CURRENT_DISAGREE_WARN 42
#define CTRL_MOTOR3_CURRENT_DISAGREE_WARN 43
#define CTRL_MOTOR4_CURRENT_DISAGREE_WARN 44
#define CTRL_MOTOR1_BLOCK_WARN 51
#define CTRL_MOTOR2_BLOCK_WARN 52
#define CTRL_MOTOR3_BLOCK_WARN 53
#define CTRL_MOTOR4_BLOCK_WARN 54
#define CTRL_MOTOR1_ECD_DISAGREE_WARN 61
#define CTRL_MOTOR2_ECD_DISAGREE_WARN 62
#define CTRL_MOTOR3_ECD_DISAGREE_WARN 63
#define CTRL_MOTOR4_ECD_DISAGREE_WARN 64
#define CTRL_MOTOR1_OFFLINE_WARN 71
#define CTRL_MOTOR2_OFFLINE_WARN 72
#define CTRL_MOTOR3_OFFLINE_WARN 73
#define CTRL_MOTOR4_OFFLINE_WARN 74

#define RED "\033[31m"
#define AMBER "\033[33m"
#define CYAN "\033[36m"

void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

void strFormat(const std::string& str, int underlineBegin, int underlineEnd, const std::string& color)
{
    std::string beginUnderline = "\033[4m";
    std::string endUnderline = "\033[24m";

    std::cout << color;
    std::cout << str.substr(0, underlineBegin);
    std::cout << beginUnderline;
    std::cout << str.substr(underlineBegin, underlineEnd - underlineBegin);
    std::cout << endUnderline;
    std::cout << str.substr(underlineEnd) << std::endl;
}

void ECAM_MSG_DSPY(int errID)
{
    switch (errID)
    {
        case CTRL_MOTOR1_OVHT_CAUT:
            strFormat("CTRL MOTOR1 OVHT", 0, 4, AMBER);
            break;
        case CTRL_MOTOR2_OVHT_CAUT:
            strFormat("CTRL MOTOR2 OVHT", 0, 4, AMBER);
            break;
        case CTRL_MOTOR3_OVHT_CAUT:
            strFormat("CTRL MOTOR3 OVHT", 0, 4, AMBER);
            break;
        case CTRL_MOTOR4_OVHT_CAUT:
            strFormat("CTRL MOTOR4 OVHT", 0, 4, AMBER);
            break;
        case CTRL_MOTOR1_OVHT_WARN:
            strFormat("CTRL MOTOR1 OVHT", 0, 4, RED);
            break;
        case CTRL_MOTOR2_OVHT_WARN:
            strFormat("CTRL MOTOR2 OVHT", 0, 4, RED);
            break;
        case CTRL_MOTOR3_OVHT_WARN:
            strFormat("CTRL MOTOR3 OVHT", 0, 4, RED);
            break;
        case CTRL_MOTOR4_OVHT_WARN:
            strFormat("CTRL MOTOR4 OVHT", 0, 4, RED);
            break;
        case CTRL_MOTOR1_CURRENT_DISAGREE_CAUT:
            strFormat("CTRL MOTOR1 CURRENT DISAGREE", 0, 4, AMBER);
            break;
        case CTRL_MOTOR2_CURRENT_DISAGREE_CAUT:
            strFormat("CTRL MOTOR2 CURRENT DISAGREE", 0, 4, AMBER);
            break;
        case CTRL_MOTOR3_CURRENT_DISAGREE_CAUT:
            strFormat("CTRL MOTOR3 CURRENT DISAGREE", 0, 4, AMBER);
                    break;
        case CTRL_MOTOR4_CURRENT_DISAGREE_CAUT:
            strFormat("CTRL MOTOR4 CURRENT DISAGREE", 0, 4, AMBER);
            break;
        case CTRL_MOTOR1_CURRENT_DISAGREE_WARN:
            strFormat("CTRL MOTOR1 CURRENT DISAGREE", 0, 4, RED);
            break;
        case CTRL_MOTOR2_CURRENT_DISAGREE_WARN:
            strFormat("CTRL MOTOR2 CURRENT DISAGREE", 0, 4, RED);
            break;
        case CTRL_MOTOR3_CURRENT_DISAGREE_WARN:
            strFormat("CTRL MOTOR3 CURRENT DISAGREE", 0, 4, RED);
            break;
        case CTRL_MOTOR4_CURRENT_DISAGREE_WARN:
            strFormat("CTRL MOTOR4 CURRENT DISAGREE", 0, 4, RED);
            break;
        case CTRL_MOTOR1_BLOCK_WARN:
            strFormat("CTRL MOTOR1 BLOCK", 0, 4, RED);
            break;
        case CTRL_MOTOR2_BLOCK_WARN:
            strFormat("CTRL MOTOR2 BLOCK", 0, 4, RED);
            break;
        case CTRL_MOTOR3_BLOCK_WARN:
            strFormat("CTRL MOTOR3 BLOCK", 0, 4, RED);
            break;
        case CTRL_MOTOR4_BLOCK_WARN:
            strFormat("CTRL MOTOR4 BLOCK", 0, 4, RED);
            break;
        case CTRL_MOTOR1_ECD_DISAGREE_WARN:
            strFormat("CTRL MOTOR1 ECD DISAGREE", 0, 4, RED);
            break;
        case CTRL_MOTOR2_ECD_DISAGREE_WARN:
            strFormat("CTRL MOTOR2 ECD DISAGREE", 0, 4, RED);
            break;
        case CTRL_MOTOR3_ECD_DISAGREE_WARN:
            strFormat("CTRL MOTOR3 ECD DISAGREE", 0, 4, RED);
            break;
        case CTRL_MOTOR4_ECD_DISAGREE_WARN:
            strFormat("CTRL MOTOR4 ECD DISAGREE", 0, 4, RED);
            break;
        case CTRL_MOTOR1_OFFLINE_WARN:
            strFormat("CTRL MOTOR1 OFFLINE", 0, 4, RED);
            break;
        case CTRL_MOTOR2_OFFLINE_WARN:
            strFormat("CTRL MOTOR2 OFFLINE", 0, 4, RED);
            break;
        case CTRL_MOTOR3_OFFLINE_WARN:
            strFormat("CTRL MOTOR3 OFFLINE", 0, 4, RED);
            break;
        case CTRL_MOTOR4_OFFLINE_WARN:
            strFormat("CTRL MOTOR4 OFFLINE", 0, 4, RED);
            break;
        default:
            std::cout << "Unknown error ID: " << errID << std::endl;
            break;
    }
}

int main()
{
    while (1)
    {
        clearScreen();
        Motor_faultHandler motor1;
        Motor_faultHandler motor2;
        Motor_faultHandler motor3;
        Motor_faultHandler motor4;
        ECAM_MSG_DSPY(motor1.errGenerator());
        //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        ECAM_MSG_DSPY(motor2.errGenerator());
        //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        ECAM_MSG_DSPY(motor3.errGenerator());
        //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        ECAM_MSG_DSPY(motor4.errGenerator());

        std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    }

    return 0;
}
