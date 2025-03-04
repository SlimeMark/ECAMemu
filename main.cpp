#include <iostream>
#include <Motor_faultHandler.h>
#include <thread>
#include <vector>
#include <algorithm>



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

void ECAM_MSG_DSPY(const std::vector<int>& errIDs)
{
    std::vector<int> warnIDs;
    std::vector<int> cautIDs;


    for (int errID : errIDs)
    {
        if (errID / 100 == 2) // WARN IDs start with 2
        {
            warnIDs.push_back(errID);
        }
        else if (errID / 100 == 1) // CAUT IDs start with 1
        {
            cautIDs.push_back(errID);
        }
    }

    for (int errID : warnIDs)
    {
        switch (errID)
        {
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

    for (int errID : cautIDs)
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
            default:
                std::cout << "Unknown error ID: " << errID << std::endl;
                break;
        }
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

        std::vector<int> errIDs;
        errIDs.push_back(motor1.errGenerator(1));
        errIDs.push_back(motor2.errGenerator(2));
        errIDs.push_back(motor3.errGenerator(3));
        errIDs.push_back(motor4.errGenerator(4));

        ECAM_MSG_DSPY(errIDs);

        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }

    return 0;
}
