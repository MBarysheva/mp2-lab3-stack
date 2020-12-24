#include "../stack/Stack.h"

#include "gtest.h"

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack <int> st);
}
TEST(TStack, check_IsEmpty_with_empty_stack)
{
	Stack<int> st;
	EXPECT_EQ(true, st.Empty());
}
TEST(TStack, check_IsEmpty_with_not_empty_stack)
{
	Stack<int> st;
	st.Push(2);
	EXPECT_EQ(false, st.Empty());
}
TEST(TStack, check_IsFull_with_full_stack)
{
	Stack<int> st;
	st.Push(1);
	st.Push(2);
	EXPECT_EQ(true, st.Full());
}
TEST(TStack, throws_when_Pop_stack_IsEmty)
{
	Stack<int> st;
	ASSERT_ANY_THROW(st.Pop());
}

