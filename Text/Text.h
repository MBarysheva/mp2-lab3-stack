#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include "../stack/Stack.h"
using namespace std;
const int maxlenght = 200;
class TTextLink
{
public:
	TTextLink* pNext, * pDown;
	char str[200];
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
	~TTextLink() {};
};
class TText {
	TTextLink* pFirst, * pCurr;
	Stack<TTextLink*> st;
	int level;
public:
	TText(TTextLink* pf = NULL)
	{
		if (!pf) pf = new TTextLink;

		pFirst = pf;
		pCurr = pFirst;
	}
	~TText() {};
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
		if (pCurr != NULL)
		{
			TTextLink* t;
			t = new TTextLink(s, pCurr->pNext, NULL);
			pCurr->pNext = t;
		}
	}
	void InsDownLine(char* s)
	{
		if (pCurr != NULL)
		{
			TTextLink* t;
			t = new TTextLink(s, pCurr->pDown, NULL);
			pCurr->pDown = t;
		}
	}
	void InsNextSection(char* s)
	{
		if (pCurr != NULL)
		{
			TTextLink* t;
			t = new TTextLink(s, NULL, pCurr->pNext);
			pCurr->pNext = t;
		}
	}
	void InsDownSection(char *s)
	{
		if (pCurr->pNext != NULL)
		{
			TTextLink* t;
			t = new TTextLink(s, NULL, pCurr->pDown);
			pCurr->pDown = t;
		}
	}
	void DelNextLine()
	{
		if (pCurr->pNext!=NULL)
		{
			TTextLink* t = pCurr->pNext;
			pCurr->pNext = t ->pNext;
			delete t;
		}
	}
	void DelDownLine()
	{
		if (pCurr->pDown!=NULL)
		{
			TTextLink* t = pCurr->pDown;
			pCurr->pDown = t->pNext;
			delete t;
		}
	}
	void Print()
	{
		level = 0;
		PrintRec(pFirst);
	}
	void PrintRec(TTextLink* t)
	{
		if (t != NULL)
			for (int i = 0; i < level; i++)
				cout << ' ';
		cout << t->str << '\n';
		level++;
		PrintRec(t->pDown);
		level--;
		PrintRec(t->pNext);
	}
	void Save(char* name)
	{
		ofstream ofs(name);
		SaveRec(pFirst, ofs);
		ofs.close();
	}
	void SaveRec(TTextLink* t, ofstream& ofs)
	{
		if (t != NULL)
		{
			ofs << t->str << endl;
			if (t->pDown != NULL)
			{
				ofs << ' { ' << endl;
				SaveRec(t->pDown, ofs);
				ofs << '}' << endl;
			}
			if (t->pNext != NULL)
			{
				SaveRec(t->pNext, ofs);
			}
		}
	}
	void Read(char* fn)
	{
		ifstream ifs(fn);
		pFirst = ReadRec(ifs);
		ifs.close();
	}
	TTextLink* ReadRec(ifstream& ifs)
	{
		TTextLink* pf = NULL, * pc = NULL;
		char Buff[maxlenght];
		while (ifs.eof() == 0)
		{
			ifs.getline(Buff, maxlenght, '\n');
			if (Buff[0] == '}')
			{
				break;
			}
			if (Buff[0] == '{')
			{
				pc->pDown = ReadRec(ifs);
			}
			if (pc == NULL)
			{
				TTextLink* tmp = new TTextLink(Buff);
				pf = pc = tmp;
			}
			else
			{
				TTextLink* tmp = new TTextLink(Buff);
				pc->pNext = tmp;
			}
		}
		return pf;
	}
	void Reset()
	{
		if (pFirst)
		{
			st.Clear();
			pCurr = pFirst;
			st.Push(pFirst);
			if (pFirst->pNext)
			{
				st.Push(pFirst->pNext);
			}
			if (pFirst->pDown)
			{
				st.Push(pFirst->pDown);
			}
		}

	}
	void GoNext()
	{
		if (!IsEnd())
		{
			pCurr = st.Pop();
			if (pCurr != pFirst)
				if (pCurr->pNext)
				{
					st.Push(pCurr->pNext);
				}
			if (pCurr->pDown)
			{
				st.Push(pCurr->pDown);
			}
		}
	}
	bool IsEnd()
	{
		return st.Empty();
	}
};
