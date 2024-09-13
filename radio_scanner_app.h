#pragma once

#include <gui/gui.h>
#include <gui/view_port.h>
#include <subghz/devices/devices.h>

typedef enum {
    ScanDirectionUp,
    ScanDirectionDown,
} ScanDirection;

typedef struct {
    Gui* gui;
    ViewPort* view_port;
    FuriMessageQueue* event_queue;
    bool running;
    uint32_t frequency;
    float rssi;
    float sensitivity;
    bool scanning;
    const SubGhzDevice* radio_device;
    ScanDirection scan_direction; 
} RadioScannerApp;

RadioScannerApp* radio_scanner_app_alloc();
void radio_scanner_app_free(RadioScannerApp* app);
int32_t radio_scanner_app(void* p);