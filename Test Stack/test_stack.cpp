#include "../stack/Stack.h"

#include "gtest.h"

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack <int> st(3));
}
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> st(5));
}
TEST(TStack, can_create_stack_with_negativ_length)
{
	ASSERT_ANY_THROW(Stack<int>st(-1));
}
TEST(TStack, check_IsEmpty_with_empty_stack)
{
	Stack<int> st(5);
	EXPECT_EQ(true, st.Empty());
}
TEST(TStack, check_IsEmpty_with_not_empty_stack)
{
	Stack<int> st(5);
	st.Push(2);
	EXPECT_EQ(false, st.Empty());
}
TEST(TStack, check_IsFull_with_full_stack)
{
	Stack<int> st(2);
	st.Push(1);
	st.Push(2);
	EXPECT_EQ(true, st.Full());
}
TEST(TStack, check_IsFull_with_not_full_stack)
{
	Stack<int> st(5);
	st.Push(2);
	EXPECT_EQ(false, st.Full());
}
TEST(TStack, throws_when_Pop_stack_IsEmty)
{
	Stack<int> st(5);
	ASSERT_ANY_THROW(st.Pop());
}
TEST(TStack, throws_when_Push_stack_IsFull)
{
	Stack<int> st(2);
	st.Push(1);
	st.Push(2);
	ASSERT_ANY_THROW(st.Push(2));
}