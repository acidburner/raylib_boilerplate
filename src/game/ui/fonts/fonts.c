

#include "fonts.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

FontManager *create_font_manager(void) {
    FontManager *manager = (FontManager *)malloc(sizeof(FontManager));
    if (manager) {
        manager->loadedFonts = NULL;
        manager->fontCount = 0;
    }
    return manager;
}
void destroy_font_manager(FontManager *manager) {
    if (!manager) {
        return;
    }
    //unload all fonts
    for (int i = 0; i < manager->fontCount; i++) {
        unload_font(manager, manager->loadedFonts[i]);
    }
    free(manager->loadedFonts);
    free(manager);
}
Font *load_font(FontManager *manager, const char *fontPath, int size) {
    if (!manager || !fontPath) {
        return NULL;
    }
    //check if font already loaded
    for (int i = 0; i < manager->fontCount; i++) {
        if (strcmp(manager->loadedFonts[i]->fontPath, fontPath) == 0 && manager->loadedFonts[i]->size == size) {
            return manager->loadedFonts[i];
        }
    }
    //load new font
    Font *newFont = (Font *)malloc(sizeof(Font));
    if (!newFont) {
        return NULL;
    }
    newFont->fontPath = strdup(fontPath);
    newFont->fontName = strdup(fontPath); //for debug purposes, could extract name from path
    newFont->size = size;
    //add to manager
    manager->loadedFonts = (Font **)realloc(manager->loadedFonts, sizeof(Font *) * (manager->fontCount + 1));
    manager->loadedFonts[manager->fontCount] = newFont;
    manager->fontCount++;
    return newFont;
}
void unload_font(FontManager *manager, Font *font) {
    if (!manager || !font) {
        return;
    }
    //find font in manager
    for (int i = 0; i < manager->fontCount; i++) {
        if (manager->loadedFonts[i] == font) {
            //remove from array
            free(font->fontPath);
            free(font->fontName);
            free(font);
            for (int j = i; j < manager->fontCount - 1; j++) {
                manager->loadedFonts[j] = manager->loadedFonts[j + 1];
            }
            manager->fontCount--;
            manager->loadedFonts = (Font **)realloc(manager->loadedFonts, sizeof(Font *) * manager->fontCount);
            return;
        }
    }
}
Font *get_font(FontManager *manager, const char *fontName, int size) {
    if (!manager || !fontName) {
        return NULL;
    }
    for (int i = 0; i < manager->fontCount; i++) {
        if (strcmp(manager->loadedFonts[i]->fontName, fontName) == 0 && manager->loadedFonts[i]->size == size) {
            return manager->loadedFonts[i];
        }
    }
    return NULL;
}