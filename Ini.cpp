#include "stdafx.h"
#include "Ini.h"

CIni::CIni(LPCTSTR szFileName)
{
	m_szFileName = szFileName;
}

LPTSTR CIni::ReadString(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefaultValue)
{
	LPTSTR szResult;
	GetPrivateProfileString(szSection, szKey,
		szDefaultValue, szResult, 255, m_szFileName);
	return szResult;
}

void CIni::WriteString(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szValue)
{
	WritePrivateProfileString(szSection, szKey, szValue, m_szFileName);
}