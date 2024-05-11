#include "test_data.h"
#include "TX2_60.h"

TX2_60 robot;

bool fwdTest()
{
    bool ret = false;
    double pose_ret[6] = {0, 0, 0, 0, 0, 0};
    double T[4][4];

    for (size_t i = 0; i < 10; i++)
    {
        robot.fwd_kinemtaic(q[i], T);
        robot.T2pose(T, pose_ret);

        if (pose_ret[0] == pose[i][0] && pose_ret[1] == pose[i][1] && pose_ret[2] == pose[i][2] &&
            pose_ret[3] == pose[i][3] && pose_ret[4] == pose[i][4] && pose_ret[5] == pose[i][5])
        {
            ret = ret && true;
        }
        else
        {
            ret = ret && false;
            break;
        }

        printf("pose_ret: %f, %f, %f, %f, %f, %f\n", pose_ret[0], pose_ret[1], pose_ret[2], pose_ret[3], pose_ret[4], pose_ret[5]);
        printf("pose: %f, %f, %f, %f, %f, %f\n", pose[i][0], pose[i][1], pose[i][2], pose[i][3], pose[i][4], pose[i][5]);
        printf("ret: %d\n", ret);
    }

    return ret;
}

bool invTest(double pose[][6], double q[][6])
{
    return false;
}