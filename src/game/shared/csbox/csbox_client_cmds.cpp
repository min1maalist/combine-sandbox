#include "cbase.h"
#include "vstdlib/random.h"
#include "GameUI/IGameUI.h"
#include "vgui_controls/Panel.h"
#include "vgui_controls/Button.h"
#include "vgui/ISurface.h"
#include "filesystem.h"
#include <vgui_controls/HTML.h>
#include "ienginevgui.h"
#include <vector>

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

// math owo
CON_COMMAND(csbox_equal, "Returns 1 if the two values are equal, otherwise returns 0\nUSAGE: csbox_equal <VALUE A> <VALUE B>")
{
	if (args.ArgC() <= 2)
	{
		Msg("USAGE: csbox_equal <VALUE A> <VALUE B>\n");
		return;
	}
	if (strcmp(args[1], args[2]) == 0)
	{
		Msg("1\n");
	}
	else
	{
		Msg("0\n");
	}
}

// browser owo
CON_COMMAND(combinebrowser, "Opens the Combine Sandbox Browser Duh")
{
    ShowHTMLBrowser(enginevgui->GetPanel(PANEL_GAMEUIDLL));
    g_pHTMLBrowser->OpenURL("https://www.google.com");
}

class OverrideInterface
{
 public:
  virtual void Create( vgui::VPANEL parent ) = 0;
  virtual vgui::VPANEL GetPanel( void ) = 0;
  virtual void Destroy( void ) = 0;

  virtual BaseMenu *GetMenuBase() = 0;
};

extern OverrideInterface *OverrideUI;
extern BaseMenu* guiroot;

class CHTMLBrowser : public vgui::Frame
{
    DECLARE_CLASS_SIMPLE(CHTMLBrowser, vgui::Frame);

public:
    CHTMLBrowser(vgui::VPANEL parent);
    ~CHTMLBrowser() override;

    void OpenURL(const char* url);
    void OnCommand(const char* command) override;

private:
    vgui::HTML* m_pHTML;
    vgui::TextEntry* m_pURLInput;
    vgui::Button* m_pGoButton;
    vgui::Button* m_pBackButton;
    vgui::Button* m_pForwardButton;
    vgui::Button* m_pReloadButton;

    char m_szCurrentURL[1024];

    void UpdateURLField();
};