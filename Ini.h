#pragma once

class CIni
{
public:
	CIni(LPCTSTR szFileName);
	LPTSTR ReadString(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szDefaultValue);
	void WriteString(LPCTSTR szSection, LPCTSTR szKey, LPCTSTR szValue);
private:
	LPCTSTR m_szFileName;
};
