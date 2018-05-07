// CParser.cpp: implementation of the CParser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Robotech.h"
#include "CParser.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParser::CParser()
{

}

CParser::~CParser()
{

}

void CParser::ChopString(CString str)
{
	if (str == "") return;
	int marker =0;
	for(int i=0; i< str.GetLength(); i++)
	{
		if(str[i] == '&'){
			DecipherData(str.Mid(marker,i-marker)); //or i-marker
			marker = i+1;
		}

		if(i == str.GetLength()-1)
		{
			DecipherData(str.Mid(marker, str.GetLength()-marker));
		}
		
	}

}

void CParser::Input(int index, int number)
{
	data[index] = number;
	TRACE("key= %i value= %i\n", index, number);
}

void CParser::DecipherData(CString frag)
{
	TRACE("The fragment is %s \n", frag);
	frag.TrimLeft(); frag.TrimRight();
	CString left, right, temp;
	int pos = frag.Find(":");
	left = frag.Left(pos);
	
	int length = left.GetLength();
	int length2 = frag.GetLength() - length;
	
	
	right = frag.Right(length2); right.Replace(":"," ");
	//TRACE("%s \n", right);
	left.TrimLeft(); left.TrimRight();
	right.TrimLeft(); right.TrimRight();
	
	TRACE("%s \n", left);
	//add a routine for sql queries
	if(isdigit(left[0]))
	{
		Input(atoi(left),atoi(right));
	}
	else
		QueryInput(left, atoi(right));

}

void CParser::GetData(CMap<int, int&, int, int&> & x)
{
	if(data.IsEmpty()) return;

	POSITION pos = data.GetStartPosition();
	while (pos != NULL){
		int k, i;
		data.GetNextAssoc( pos, k, i );
		x [k] = i;
	}
}


void CParser::CleanData()
{
	data.RemoveAll();
}

void CParser::QueryInput(CString query, int value)
{
	
	SkillSet skillset;
	skillset.m_strFilter = query;
	skillset.Open();

	while(!skillset.IsEOF())
	{
		int id = skillset.m_ID;
		Input(id, value);
		skillset.MoveNext();
	}

}
