//========= Copyright � 2009-20xx, Combine Sandbox, All rights reserved. ============//
//
// Purpose: 
//
// For my Linux Homies
//=============================================================================//

#include "cbase.h"

const tchar* GetProcessorArchName()
{
#if defined( __x86_64__) || defined(_M_X64)
    return "amd64";
#elif defined(__i386__) || defined(_X86_) || defined(_M_IX86)
    return "i386";
#elif defined __aarch64__
    return "aarch64";
#elif defined __arm__ || defined _M_ARM
    return "arm";
#else
    return "Unknown architecture";
#endif
}

const tchar* GetPlatformName()
{
#ifdef LINUX	
    return "Linux";
#elif ANDROID 
    return "Android";
#elif PLATFORM_FBSD
    return "FreeBSD";
#elif PLATFORM_BSD
    return "BSD";
#elif WIN32
    return "Windows";
#elif OSX
    return "MacOS";
#elif PLATFORM_HAIKU
    return "Haiku";
#else
    return "Unknown Platform"
#endif
}

const tchar* GetGame()
{
#if defined( HL2_CLIENT_DLL ) && !defined(HL2SB)
    return "Combine Sandbox";
#elif defined(PORTAL_CLIENT_DLL) && !defined(HL2SB)
    return "Combine Sandbox";
#elif defined(HL1_CLIENT_DLL) && !defined(HL2SB)
    return "Combine Sandbox";
#elif defined(HL2MP) && !defined(HL2SB)
    return "Combine Sandbox";
#elif defined CSBOX && defined ( HL2_CLIENT_DLL )
    return "Combine Sandbox";
#else
    return "Unknown Version";
#endif
}

void csboxfetch(void)
{
    Msg("\x01\x03 .-*#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+.\n"
        "\x01\x03 .=%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.\n"
        "\x01\x03 @@@@@@@#+:   ..-*@@@@@@@@@@@@@@@@@@@@@@@@*\n"
        "\x01\x03 -#%+:              .-*@@@@@@@@@@@@@@@@@@@@\n"
        "\x01\x03                       -%@@@@@@@@@@@@@@@@%\n"
        "       .....          \x01\x03 .-@@@@@@@@@@@@@@@-\n"
        "  :*@@@@@@@@@@@*-       \x01\x03 .#@@@@@@@@@@@@+.\n"
        " .%@@@@@@@@@@@@@@@@.     \x01\x03  .#@@@@@@@@@@#\n"
        ".+@@@@@-     :%@@@@#.       \x01\x03.#@@@@@@@@#.\n"
        ".*@@@@@*..    :-----.       \x01\x03 :@@@@@@@@:\n"
        "=@@@@@@@@@@%=.             \x01\x03 .#@@@@@@=\n"
        "   .+@@@@@@@@@@@@@%+.       \x01\x03  .*@@@@@+\n"
        "     ..:*%%@@@@@@@@@:       \x01\x03 .*@@@@#.\n"
        "           ..:#@@@@@*       \x01\x03 .#@@@@:\n"
        ":%@@@@*.      =@@@@@+       \x01\x03 -@@@@-\n"
        ".=@@@@@@#:..-%@@@@@%:      \x01\x03 .@@@@=\n"
        "  :#@@@@@@@@@@@@@@+.       \x01\x03.%@@@*.\n"
        "     :+##%%%%#*=.       \x01\x03  :%@@@%.\n"
        "                      \x01\x03  .*@@@@*.\n"
        "                     \x01\x03  -@@@@@-.\n"
        "                   \x01\x03    .%@@+.\n"
        "\n");
    Msg("Engine: Source Engine\n");
    Msg("Platform: %s\n", GetPlatformName());
    Msg("Arch: %s\n", GetProcessorArchName());
    Msg("Game: %s\n", GetGame());
}

ConCommand neofetch("neofetch", csboxfetch, "");

CON_COMMAND(friendlyfire, "Friendly Fire for Combine Sandbox") {
    engine->ClientCmd("ent_create ai_relationship subject !player target * disposition 1 rank 99 reciprocal 0 startactive 1");
}

CON_COMMAND(toolgun, "Toolgun Utils") {
    Msg("TOOLGUN - COMBINE SANDBOX EDITION");
    engine->ClientCmd("echo '1. Friendly Fire'"); 
    engine->ClientCmd("echo '2. Infinite ammo + All weapons'");
    engine->ClientCmd("echo '3. Shitify the graphics'");
    engine->ClientCmd("alias 1 'friendlyfire'");
    engine->ClientCmd("alias 2 'sv_cheats 1;impulse 101;give weapon_physgun'");
    engine->ClientCmd("alias 3 'sv_cheats 1; mat_dxlevel 60; cl_ragdoll_collide 0; mat_picmip 4; r_WaterDrawReflection 0; r_WaterDrawRefraction 0; mat_wateroverlaysize 8; r_lod 5; mat_fullbright 1; mat_diffuse 5; mat_bumpmap 0; r_shadows 0; mat_fullbright 1; mat_forceaniso 0; mat_forcehardwaresync 0; mat_reducefillrate 0; mat_mipmaptextures 0; mat_filtertextures 0; mat_bloom 0; mat_envmapsize 32; mat_envmapgasize 8; mat_antialiasing 0; cl_phys_props_enable 0; mat_filterlightmaps 0; mat_showlowresimage 1");
}