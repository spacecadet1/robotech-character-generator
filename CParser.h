// CParser.h: interface for the CParser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPARSER_H__91A4382C_0CA1_4244_8660_8A925F0D5FB3__INCLUDED_)
#define AFX_CPARSER_H__91A4382C_0CA1_4244_8660_8A925F0D5FB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CParser  
{
public:
	void CleanData();
	void DecipherData ( CString frag );
	void GetData (CMap<int, int&, int, int&> &x);
	void Input( int index, int number);
	void ChopString( CString str );
	CParser();
	virtual ~CParser();

private:
	void QueryInput ( CString query, int value );
	CMap<int, int&, int, int&> data;
	
};

#endif // !defined(AFX_CPARSER_H__91A4382C_0CA1_4244_8660_8A925F0D5FB3__INCLUDED_)
