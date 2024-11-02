//========= Copyright Combine Sandbox, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//
#include "cbase.h"
#include "iclientmode.h"
#include <vgui_controls/Frame.h>
#include <vgui_controls/Controls.h>
#include <vgui_controls/PanelListPanel.h>
#include <vgui_controls/PropertyPage.h>
#include <vgui_controls/PropertyDialog.h>
#include <vgui_controls/PropertySheet.h>
#include <vgui_controls/TextEntry.h>
#include <vgui_controls/Button.h>
#include "game_controls/basemodel_panel.h"

class CSToolMenu : public vgui::PropertyPage
{
	typedef vgui::PropertyPage BaseClass;
public:
	CSToolMenu( vgui::Panel *parent, const char *panelName );

	virtual void OnTick( void );
	virtual void OnCommand( const char *pcCommand );
private:
	vgui::TextEntry *m_Red; 
	vgui::TextEntry *m_Green;
	vgui::TextEntry *m_Blue; 
	vgui::TextEntry *m_Modelscale; 
	vgui::TextEntry *m_EntCreate;
};

class CSModels : public vgui::PropertyPage
{
	typedef vgui::PropertyPage BaseClass;

public:
	CSModels( vgui::Panel *parent, const char *panelName );
	const char *GetText();
	virtual void InitModels( Panel *panel, const char *modeltype, const char *modelfolder, const char *mdlPath  );
	virtual void OnCommand( const char *command );

private:
	vgui::ComboBox *box;
	CMDLPanel *mdl;

	char sz_mdlname[260];
};

class CSList : public vgui::PanelListPanel
{
public:
	typedef vgui::PanelListPanel BaseClass;

	CSList( vgui::Panel *parent, const char *pName );

	virtual void OnTick( void );
	virtual void OnCommand( const char *command );
	virtual void PerformLayout();
	virtual void AddImageButton( vgui::PanelListPanel *panel, const char *image, const char *hover, const char *command );
	virtual void AddModelPanel( vgui::PanelListPanel *panel, const char *mdlname, const char *cmd );
	virtual void InitEntities( KeyValues *kv, vgui::PanelListPanel *panel, const char *enttype );
	virtual void InitModels( vgui::PanelListPanel *panel, const char *modeltype, const char *modelfolder, const char *mdlPath );
private:
	CUtlVector<vgui::Panel *> m_LayoutItems;
};

class CSMenu : public vgui::PropertyDialog
{
	typedef vgui::PropertyDialog BaseClass;
public:
	CSMenu( vgui::VPANEL *parent, const char *panelName );
	void OnTick();
	void OnCommand( const char *command ); 
};

class CSPanel
{
public:
	virtual void		Create(vgui::VPANEL parent) = 0;
	virtual void		Destroy(void) = 0;
	virtual void		Activate(void) = 0;
};

extern CSPanel* csbox_menu;