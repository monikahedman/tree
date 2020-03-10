/**
 * @file    Settings.h
 *
 * This file contains various settings and enumerations that you will need to use in the various
 * assignments. The settings are bound to the GUI via static data bindings.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include "RGBA.h"

// Enumeration values for the Shapes that the user can select in the GUI.
enum ShapeType {
    SHAPE_CUBE,
    SHAPE_CONE,
    SHAPE_SPHERE,
    SHAPE_CYLINDER,
    SHAPE_TORUS,
    SHAPE_SPECIAL_1,
    SHAPE_SPECIAL_2,
    NUM_SHAPE_TYPES
};

// Enumeration values for the currently selected scene type
enum SceneMode {
    SCENEMODE_FINAL
};

// Enumeration values for the currently selected camera type
enum CameraMode {
    CAMERAMODE_ORBIT,
    CAMERAMODE_CAMTRANS
};

/**
 * @struct Settings
 *
 * Stores application settings for the CS123 GUI.
 *
 * You can access all app settings through the "settings" global variable.
 * The settings will be automatically updated when things are changed in the
 * GUI (the reverse is not true however: changing the value of a setting does
 * not update the GUI).
*/
struct Settings {
    // Loads settings from disk, or fills in default values if no saved settings exist.
    void loadSettingsOrDefaults();

    // Saves the current settings to disk.
    void saveSettings();

    // Final
    float branchLength;
    float branchRadius;
    float branchAngle;
    float leafSize;
    float leafWidth;
    bool raindropsOnWindowEnabled;
    int rainParticleCount;
    bool rainEnabled;

    // Lights
    bool randomEnabled;
    int lightCount;
    int lightColorRed;
    int lightColorGreen;
    int lightColorBlue;
    float lightRadius;
    float lightBrightness;

    // Camtrans
    bool useOrbitCamera;        // Use the built-in orbiting camera instead of the Camtrans camera
    float cameraPosX;
    float cameraPosY;
    float cameraPosZ;
    float cameraRotU;
    float cameraRotV;
    float cameraRotN;
    float cameraFov;            // The camera's field of view, which is twice the height angle.
    float cameraNear;           // The distance from the camera to the near clipping plane.
    float cameraFar;            // The distance from the camera to the far clipping plane.

    int getSceneMode();
    int getCameraMode();


};

// The global Settings object, will be initialized by MainWindow
extern Settings settings;

#endif // SETTINGS_H
