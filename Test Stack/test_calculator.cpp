#include "../stack/Calculator.h"
#include "../stack/Stack.cpp"
#include "gtest.h"
TEST(TCalculator, can_create_a_calculator)
{
    ASSERT_NO_THROW(TCalculator calc);
}

TEST(TCalculator, can_add_expression_to_calculator)
{
    TCalculator calc;
     string str = "a+b";
    ASSERT_NO_THROW(calc.SetFormula(str));
}
TEST(TCalculator, can_get_postfix)
{
    TCalculator calc;
    string str = "a+b";
    calc.SetFormula(str);
    calc.ToPostfix();
    ASSERT_NO_THROW(calc.GetPostfix());
}
TEST(TCalculator, can_get_the_result_of_expression)
{
    TCalculator calc;
    calc.SetFormula("2+1");
    calc.ToPostfix();
    ASSERT_NO_THROW(calc.CalcPostfix());
}
TEST(Calculator, cannot_get_the_result_of_expression)
{
    TCalculator calc;
    string str = "/+3+5";
    calc.SetFormula(str);
    calc.ToPostfix();
    ASSERT_ANY_THROW(calc.CalcPostfix());
}
TEST(TCalculator, can_get_the_result_of_long_expression)
{
    TCalculator calc;
    calc.SetFormula("(2+8)/(2^3)+(3^2)*4-8*7+9^(1/2)-5*2");
    calc.ToPostfix();
    ASSERT_NO_THROW(calc.CalcPostfix());
}
TEST(TCalculator, check_of_the_result_of_long_expression)
{
    TCalculator calc;
    calc.SetFormula(("(2+8)/(2^3)+(3^2)*4-8*7+9^(1/2)-5*2"));
    calc.ToPostfix();
    EXPECT_EQ(-25.75, calc.CalcPostfix());
}
TEST(TCalculator, can_add_numbers)
{
    TCalculator calc;
    string str = "3+5";
    calc.SetFormula(str);
    calc.ToPostfix();
    EXPECT_EQ(8, calc.CalcPostfix());
}
TEST(TCalculator, can_subtract_numbers)
{
    TCalculator calc;
    string str = "9-3";
    calc.SetFormula(str);
    calc.ToPostfix();
    EXPECT_EQ(6, calc.CalcPostfix());
}
TEST(TCalculator, can_multiply_numbers)
{
    TCalculator calc;
    string str = "3*5";
    calc.SetFormula(str);
    calc.ToPostfix();
    EXPECT_EQ(15, calc.CalcPostfix());
}
TEST(TCalculator, can_divide_numbers)
{
    TCalculator calc;
    string str = "9/3";
    calc.SetFormula(str);
    calc.ToPostfix();
    EXPECT_EQ(3, calc.CalcPostfix());
}
TEST(TCalculator, can_pow_numbers)
{
    TCalculator calc;
    string str = "3^2";
    calc.SetFormula(str);
    calc.ToPostfix();
    EXPECT_EQ(9, calc.CalcPostfix());
}