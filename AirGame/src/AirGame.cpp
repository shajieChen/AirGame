/**
 * @file AirGame.cpp
 * @date 23-Apr-2020
 */

#define __SCROLL_IMPL__
#include "AirGame.h"
#undef __SCROLL_IMPL__

#include "Object.h"

#define orxIMGUI_HEADER_ONLY
#include "orxImGui.cpp"
#undef orxIMGUI_HEADER_ONLY

#define orxARCHIVE_HEADER_ONLY
#include "orxArchive.cpp"
#undef orxARCHIVE_HEADER_ONLY

/** Update function, it has been registered to be called every tick of the core clock
 */
void AirGame::Update(const orxCLOCK_INFO &_rstInfo)
{
    // Should quit?
    if(orxInput_IsActive("Quit"))
    {
        // Send close event
        orxEvent_SendShort(orxEVENT_TYPE_SYSTEM, orxSYSTEM_EVENT_CLOSE);
    }
}

/** Init function, it is called when all orx's modules have been initialized
 */
orxSTATUS AirGame::Init()
{
    // Display a small hint in console
    orxLOG("\n* This template project creates a simple scene"
    "\n* You can play with the config parameters in ../data/config/AirGame.ini"
    "\n* After changing them, relaunch the executable to see the changes.");

    // Display additional Dear ImGui hint in console
    orxLOG("\n* This template also has support for Dear ImGui.");

    // Initialize Dear ImGui
    orxImGui_Init();

    // Initialize archive (ZIP) resource type
    orxArchive_Init();

    // Create the scene
    CreateObject("Scene");

    // Done!
    return orxSTATUS_SUCCESS;
}

/** Run function, it should not contain any game logic
 */
orxSTATUS AirGame::Run()
{
    // Show Dear ImGui's demo and stats windows
    ImGui::ShowDemoWindow();
    ImGui::ShowMetricsWindow();

    // Return orxSTATUS_FAILURE to instruct orx to quit
    return orxSTATUS_SUCCESS;
}

/** Exit function, it is called before exiting from orx
 */
void AirGame::Exit()
{
    // Exits from Dear ImGui
    orxImGui_Exit();

    // Let Orx clean all our mess automatically. :)
}

/** BindObjects function, ScrollObject-derived classes are bound to config sections here
 */
void AirGame::BindObjects()
{
    // Bind the Object class to the Object config section
    ScrollBindObject<Object>("Object");
}

/** Bootstrap function, it is called before config is initialized, allowing for early resource storage definitions
 */
orxSTATUS AirGame::Bootstrap() const
{
    // Add a config storage to find the initial config file
    orxResource_AddStorage(orxCONFIG_KZ_RESOURCE_GROUP, "../data/config", orxFALSE);

    // Return orxSTATUS_FAILURE to prevent orx from loading the default config file
    return orxSTATUS_SUCCESS;
}

/** Main function
 */
int main(int argc, char **argv)
{
    // Execute our game
    AirGame::GetInstance().Execute(argc, argv);

    // Done!
    return EXIT_SUCCESS;
}
