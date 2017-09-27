#include "gtest/gtest.h"
#include "Payroll.h"

TEST(PayRollTest, test_if_invalid_salary_when_value_is_less_than_0)
{
    EXPECT_EQ(false, isValidSalaryAmount(10000));
}

TEST(PayRollTest, test_if_valid_salary_when_value_is_less_than_0)
{
    EXPECT_EQ(true, isValidSalaryAmount(30000));
}
TEST(PayRollTest, test_if_valid_hours_when_value_is_more_than_0)
{
    EXPECT_EQ(true, isValidSalaryAmount(20));
}
TEST(PayRollTest, test_if_invalid_hours_when_value_is_greater_than_60)
{
    EXPECT_EQ(false, isValidSalaryAmount(70));
}
