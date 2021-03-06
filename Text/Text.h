#pragma once
#include <iostream>
#include <cstdlib>
#include "../stack/Stack.h"
class TTextLink
{
public:
	TTextLink* pNext, * pDown;
	char str[80];
	TTextLink(char* s = NULL, TTextLink* pn = NULL, TTextLink* pd = NULL)
	{
		pNext = pn;
		pDown = pd;
		if (s)
		{
			strcpy(str, s);
		}
		else str[0] = '\0';
	}
	~TTextLink();
};
class TText {
	TTextLink* pFirst, * pCurr;
	Stack<TTextLink*> st;
public:
	void GoFirstLink() {
		pCurr = pFirst;
		st.Clear();
	}
	void GoNextLink()
	{
		if (pCurr->pNext != NULL)
		{
			st.Push(pCurr);
			pCurr = pCurr->pNext;
		}
	}
	void GoPrevLink()
	{
		if (pFirst != pCurr)
		{
			pCurr = st.Pop();
		}
	}
	void InsNextLine(char* s)
	{
		TTextLink* t;
		t = new TTextLink(s, pCurr->pNext);
		pCurr->pNext = t;
	}
	void InsNextSection(char* s)
	{
		TTextLink* t;
		t = new TTextLink(s, NULL, pCurr->pNext);
			pCurr->pNext = t;
	}
	void InsDownSection(char *s)
	{
		TTextLink* t;
		t = new TTextLink(s, NULL, pCurr->pDown);
		pCurr->pDown = t;
	}
	void DelNextLine()
	{
		if (pCurr->pNext)
		{
			TTextLink* t = pCurr->pNext;
			pCurr->pNext = t ->pNext;
			delete t;
		}
	}
	void DelDownLine()
	{
		if (pCurr->pDown)
		{
			TTextLink* t = pCurr->pDown;
			pCurr->pDown = t->pNext;
			delete t;
		}
	}
};
