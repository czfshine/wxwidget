#ifndef WXCRAFTERCB_H
#define WXCRAFTERCB_H

#include <cbplugin.h> // for "class cbPlugin"
#include <wx/treebase.h>
#include <wx/event.h>
#include "wxcLib/wxcConnector.h"
#include <vector>
#include <wx/filename.h>

class wxCrafterTab;
class FileTreeData;
class cbTreeCtrl;

class wxCrafterCB : public cbPlugin
{
    cbTreeCtrl* m_projectTree;
    wxcConnector m_connector;
    wxCrafterTab* m_tabView;

protected:
    // Event handlers
    void OnTreeItemActivated(wxTreeEvent& event);
    void OnFilesGenerated(wxCommandEvent &event);

    // Helpers
    bool IsWxCrafterFile(const FileTreeData* ftd) const;
    wxArrayString DoGetAllProjectTargets(cbProject* proj) const;
    FileTreeData* DoGetSelectedItem();

public:
    /**
     * @brief ensure wxCrafter is running
     * @return
     */
    bool EnsureWxCrafterIsRunning();

    wxcConnector& GetConnector() {
        return m_connector;
    }
    
    /** Constructor. */
    wxCrafterCB();
    /** Destructor. */
    virtual ~wxCrafterCB();


    /** This method is called by Code::Blocks and is used by the plugin
      * to add any menu items it needs on Code::Blocks's menu bar.\n
      * It is a pure virtual method that needs to be implemented by all
      * plugins. If the plugin does not need to add items on the menu,
      * just do nothing ;)
      * @param menuBar the wxMenuBar to create items in
      */
    virtual void BuildMenu(wxMenuBar* menuBar);

    /** This method is called by Code::Blocks core modules (EditorManager,
      * ProjectManager etc) and is used by the plugin to add any menu
      * items it needs in the module's popup menu. For example, when
      * the user right-clicks on a project file in the project tree,
      * ProjectManager prepares a popup menu to display with context
      * sensitive options for that file. Before it displays this popup
      * menu, it asks all attached plugins (by asking PluginManager to call
      * this method), if they need to add any entries
      * in that menu. This method is called.\n
      * If the plugin does not need to add items in the menu,
      * just do nothing ;)
      * @param type the module that's preparing a popup menu
      * @param menu pointer to the popup menu
      * @param data pointer to FileTreeData object (to access/modify the file tree)
      */
    virtual void BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data = 0);

    /** This method is called by Code::Blocks and is used by the plugin
      * to add any toolbar items it needs on Code::Blocks's toolbar.\n
      * It is a pure virtual method that needs to be implemented by all
      * plugins. If the plugin does not need to add items on the toolbar,
      * just do nothing ;)
      * @param toolBar the wxToolBar to create items on
      * @return The plugin should return true if it needed the toolbar, false if not
      */
    virtual bool BuildToolBar(wxToolBar* toolBar) {
        return false;
    }
protected:
    /** Any descendent plugin should override this virtual method and
      * perform any necessary initialization. This method is called by
      * Code::Blocks (PluginManager actually) when the plugin has been
      * loaded and should attach in Code::Blocks. When Code::Blocks
      * starts up, it finds and <em>loads</em> all plugins but <em>does
      * not</em> activate (attaches) them. It then activates all plugins
      * that the user has selected to be activated on start-up.\n
      * This means that a plugin might be loaded but <b>not</b> activated...\n
      * Think of this method as the actual constructor...
      */
    virtual void OnAttach();

    /** Any descendent plugin should override this virtual method and
      * perform any necessary de-initialization. This method is called by
      * Code::Blocks (PluginManager actually) when the plugin has been
      * loaded, attached and should de-attach from Code::Blocks.\n
      * Think of this method as the actual destructor...
      * @param appShutDown If true, the application is shutting down. In this
      *         case *don't* use Manager::Get()->Get...() functions or the
      *         behaviour is undefined...
      */
    virtual void OnRelease(bool appShutDown);
};

#endif // WXCRAFTERCB_H