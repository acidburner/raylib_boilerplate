#pragma once

// font management for the game UI
// responsibilities:
// - Load fonts from disk
// - Provide font metrics and rendering info
// - Manage font resources (caching, unloading, etc.)

// ToDo: Define font structures, loading functions, and management APIs

typedef struct Font {
    char *fontPath;
    char *fontName; //for debug purposes
    int size;
    // add more font-related members as needed
} Font;

typedef struct FontManager {
    Font **loadedFonts; //array of loaded fonts, allows multiple fonts at runtime, and/or cycling for a/b testing
    int fontCount;
    // add more font manager-related members as needed
} FontManager;

//FOnt Manager function prototypes
FontManager* create_font_manager(void);
void destroy_font_manager(FontManager *manager);
Font* load_font(FontManager *manager, const char *fontPath, int size);
void unload_font(FontManager *manager, Font *font);
Font* get_font(FontManager *manager, const char *fontName, int size);

// ToDo: api-ify this module for different rendering backends