//=================== Copyright (c) 2024 The Aridity Team, all rights reserved. ===================//
//
// Purpose: Sentry integration
//
//=================================================================================================//

#include "cbase.h"
#pragma warning ( disable : 4005 )
#pragma warning ( disable : 4700 )
#include "sentry.h"
#include "csbox_sentry_manager.h"
#include "string"

CCSBoxSentryMgr* g_SentryMgr = NULL;
CCSBoxSentryMgr* CSBoxSentryMgr() 
{
	return g_SentryMgr;
}

CCSBoxSentryMgr::CCSBoxSentryMgr()
{
	dsnLink = NULL; // unused
}
CCSBoxSentryMgr::~CCSBoxSentryMgr()
{
	delete dsnLink;
}

void CCSBoxSentryMgr::Init() 
{
	sentry_options_t* options = sentry_options_new();
	sentry_options_set_dsn(options, "https://cd8e8f25d4446e7c8eca2761e7457eff@o4508370895044608.ingest.de.sentry.io/4508370903957584");

	sentry_value_t event = sentry_value_new_event();

#ifdef GAME_DLL
	char gamePath[256];
	engine->GetGameDir(gamePath, 256);
	Q_StripTrailingSlash(gamePath);

	std::string sGamePath = gamePath;
	std::string sHandlerPath = sGamePath.append("/bin/crashpad_handler.exe");
	std::string sDbPath = sGamePath.append(".sentry-native");

	const char *handlerPath = sHandlerPath.c_str();
	const char* dbPath = sDbPath.c_str();

	sentry_options_set_handler_path(options, handlerPath);
	sentry_options_set_database_path(options, dbPath);

	sentry_value_t exc = sentry_value_new_exception("Exception/Crash", "An exception has been thrown - server");
#else
	std::string sGamePath = engine->GetGameDirectory();
	std::string sHandlerPath = sGamePath.append("/bin/crashpad_handler.exe");
	std::string sDbPath = sGamePath.append(".sentry-native");

	const char* handlerPath = sHandlerPath.c_str();
	const char* dbPath = sDbPath.c_str();

	sentry_options_set_handler_path(options, handlerPath);
	sentry_options_set_database_path(options, dbPath);

	sentry_value_t exc = sentry_value_new_exception("Exception/Crash", "An exception has been thrown - client");
#endif
	sentry_options_set_release(options, "csbox@2.0.0");
	sentry_options_set_debug(options, 1);
	sentry_options_set_environment(options, "production");

	sentry_value_set_stacktrace(exc, NULL, 0);
	sentry_event_add_exception(event, exc);

	sentry_capture_event(event);
	sentry_init(options);

#ifdef CLIENT_DLL
	ConColorMsg(Color(54, 45, 89, 255), "[ Sentry ] Sentry initialized - client\n");
#else
	ConColorMsg(Color(54, 45, 89, 255), "[ Sentry ] Sentry initialized - server\n");
#endif
}

void CCSBoxSentryMgr::Shutdown()
{
	sentry_shutdown();
}

// logging
void CCSBoxSentryMgr::SentryLog(char* message)
{
	ConMsg(message); // log through the app output also
	sentry_capture_event(sentry_value_new_message_event(
		/*   level */ SENTRY_LEVEL_INFO,
		/*  logger */ "CCSBoxSentryMgr",
		/* message */ message
	));
}
void CCSBoxSentryMgr::SentryWarn(char* message)
{
	ConMsg(message); // log through the app output also
	sentry_capture_event(sentry_value_new_message_event(
		/*   level */ SENTRY_LEVEL_WARNING,
		/*  logger */ "CCSBoxSentryMgr",
		/* message */ message
	));
}
void CCSBoxSentryMgr::SentryError(char* message)
{
	ConMsg(message); // log through the app output also
	sentry_capture_event(sentry_value_new_message_event(
		/*   level */ SENTRY_LEVEL_ERROR,
		/*  logger */ "CCSBoxSentryMgr",
		/* message */ message
	));
}
