#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/mathHelper.h"
#include "../src/test_data.h"
#include "../src/TX2_60.h"

namespace
{

    struct KinTest : public ::testing::Test
    {
        double q[10][6];
        double qc[6];

        virtual void SetUp() override
        {
        }

        virtual void TearDown() override
        {
        }
    };

    TEST(KinTest, test_kin_forward_kinematics)
    {
        EXPECT_STRNE("hello", "World");
        EXPECT_EQ(7 * 6, 42);
    }
} // namespace
// Run all the tests that were declared with TEST() <|code_middle|>
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
