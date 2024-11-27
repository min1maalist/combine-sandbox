//=================== Copyright (c) 2024 The Aridity Team, all rights reserved. ===================//
//
// Purpose: Sentry integration
//
//=================================================================================================//

#ifndef CSBOX_SENTRY_MGR_H
#define CSBOX_SENTRY_MGR_H
#ifdef _WIN32
#pragma once
#endif

#pragma warning ( disable : 4005 )

class CCSBoxSentryMgr 
{
	DECLARE_CLASS_NOBASE(CCSBoxSentryMgr);

public:
	CCSBoxSentryMgr();
	~CCSBoxSentryMgr();

	void Init();
	void Shutdown();

	void SentryLog(char* message);
	void SentryWarn(char* message);
	void SentryError(char* message);

private:
	char* dsnLink;
};

extern CCSBoxSentryMgr* CSBoxSentryMgr();

#endif // !RW_SENTRY_MGR_H

