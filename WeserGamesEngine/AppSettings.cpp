#include "WeserGamesEngine.h"

AppSettings::AppSettings()
{
    SetSetting("Project_Name", "Default Name");
    SetSetting("Project_Developer", "Default Developer");
    SetSetting("Project_version", new Version(1,0,0));
    SetSetting("Initial_resolution", Resolution::GetActiveResolution());
    SetSetting("Window_type", reinterpret_cast<int*>(WindowStyle::Windowed));
    SetSetting("Dimensional_number", reinterpret_cast<int*>(Dimensions::ThreeD));
    /*SetSetting("Shader_com_mode", &ShaderCompMode::Glsl);
    SetSetting("Input_style", &InputStyle::KeyNMouse);*/
    SetSetting("Ext_res_loc", nullptr);
    SetSetting("Renderer", reinterpret_cast<int*>(Renderers::OpenGL));
    if (GetSetting("Renderer") == (const void*)Renderers::DirectX) {
        SetSetting("DirectX level", (const void*)11);
    }
    SetSetting("Developer_mode", new bool(false));
    SetSetting("Engine_Name", new std::string("WesserGamesEngine"));
    SetSetting("Engine_dev", new std::string("WesserGames"));
    SetSetting("Engine_ver", new Version(0, 0, 1, 0));
    SetSetting("Window_Icon", nullptr);

    /*std::string* resourcepath = new std::string;
    resourcepath->append(Application::GetCurrentExeDirectory());
    resourcepath->append("\\");
    resourcepath->append("Internal\\Resources");
    SetSetting("Inter_res_loc", resourcepath);*/

    /*std::string* assetsepath = new std::string;
    assetsepath->append(Application::GetCurrentExeDirectory());
    assetsepath->append("\\");
    assetsepath->append("Assets");
    SetSetting("Inter_res_loc", assetsepath);*/

    // Lock settings
    LockSetting("Inter_res_loc");
    LockSetting("Engine_Name");
    LockSetting("Engine_dev");
    LockSetting("Engine_ver");
}

/// @brief Set's the value of or creates a setting entry
/// @param setting The setting to change or create
/// @param value The value to set the setting to
void AppSettings::SetSetting(const std::string& setting, const void* value)
{
    if (!LockedSettings.count(setting)) {
        settings[setting] = value;
    }
    else {
        throw std::runtime_error("Tried to modify a locked setting");
    }
}

/// @brief Get's the value of the created setting
/// @param setting The setting to get value of
/// @return the found value
const void* AppSettings::GetSetting(const std::string& setting)
{
    auto it = settings.find(setting);
    if (it != settings.end()) {
        return it->second;
    }
    return nullptr;
}

void AppSettings::LockSetting(const std::string& setting)
{
    auto it = settings.find(setting);
    if (it != settings.end()) {
        LockedSettings[it->first] = rand();
    }
}

void AppSettings::LockSetting(const std::string& setting, const std::string& pass)
{
    auto it = settings.find(setting);
    if (it == settings.end()) {
        LockedSettings[it->first] = pass;
    }
}

void AppSettings::UnlockSetting(const std::string&, const std::string&)
{
}
