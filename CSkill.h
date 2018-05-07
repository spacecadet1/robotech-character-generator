// CSkill.h: interface for the CSkill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CSKILL_H__99D17D24_9FCD_4C5F_8416_63337DB29BD2__INCLUDED_)
#define AFX_CSKILL_H__99D17D24_9FCD_4C5F_8416_63337DB29BD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSkill 
{
public:
	CSkill();
	virtual ~CSkill();
	int level;
	int increment;
	int base;
	CString category;
	CString skill;
	int index;
};

#endif // !defined(AFX_CSKILL_H__99D17D24_9FCD_4C5F_8416_63337DB29BD2__INCLUDED_)
