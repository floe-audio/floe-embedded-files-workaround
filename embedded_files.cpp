#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char const *data;
  uint64_t size;
} EmbeddedString;

typedef struct {
  uint8_t const *data;
  uint64_t size;
  EmbeddedString filename;
} BinaryData;

typedef struct {
  BinaryData data;
  EmbeddedString name;
  EmbeddedString folder;
  EmbeddedString tag1;
  EmbeddedString tag2;
  EmbeddedString description;
} EmbeddedIr;

typedef struct {
  EmbeddedIr const *irs;
  uint32_t count;
} EmbeddedIrs;

BinaryData EmbeddedFontAwesome();
BinaryData EmbeddedRoboto();
BinaryData EmbeddedDefaultBackground();
BinaryData EmbeddedLogoImage();
BinaryData EmbeddedIconImage();
BinaryData EmbeddedAboutLibraryTemplateRtf();
BinaryData EmbeddedPackageInstallationRtf();

EmbeddedIrs GetEmbeddedIrs();

#ifdef __cplusplus
}
#endif

//
// fn embeddedString(comptime str: []const u8) c.EmbeddedString {
//     return .{ .data = str.ptr, .size = str.len };
// }
//
// fn embeddedFile(comptime filename: []const u8) c.BinaryData {
//     const data = @embedFile(filename);
//     return .{
//         .data = data,
//         .size = data.len,
//         .filename = embeddedString(filename),
//     };
// }
//
// export fn EmbeddedFontAwesome() c.BinaryData {
//     return embeddedFile("fonts/fa-solid-900.ttf");
// }

static EmbeddedString MakeEmbeddedString(const char *str) {
  return EmbeddedString{.data = str, .size = __builtin_strlen(str)};
}

extern "C" BinaryData EmbeddedFontAwesome() {
#include "fa_solid_900.hpp"
  return BinaryData{
      .data = fa_solid_900_ttf,
      .size = sizeof(fa_solid_900_ttf),
      .filename = MakeEmbeddedString("fonts/fa-solid-900.ttf"),
  };
}

// export fn EmbeddedRoboto() c.BinaryData {
//     return embeddedFile("fonts/Roboto-Regular.ttf");
// }

extern "C" BinaryData EmbeddedRoboto() {
#include "Roboto_Regular.hpp"
  return BinaryData{
      .data = Roboto_Regular_ttf,
      .size = sizeof(Roboto_Regular_ttf),
      .filename = MakeEmbeddedString("fonts/Roboto-Regular.ttf"),
  };
}

extern "C" BinaryData EmbeddedUnknownLibraryIcon() {
#include "unknown_library_icon.hpp"
  return BinaryData{
      .data = unknown_library_icon_png,
      .size = sizeof(unknown_library_icon_png),
      .filename = MakeEmbeddedString("images/unknown_library_icon.png"),
  };
}

//
// export fn EmbeddedDefaultBackground() c.BinaryData {
//     return embeddedFile("images/default-background.jpg");
// }

extern "C" BinaryData EmbeddedDefaultBackground() {
#include "default_background.hpp"
  return BinaryData{
      .data = default_background_jpg,
      .size = sizeof(default_background_jpg),
      .filename = MakeEmbeddedString("images/default-background.jpg"),
  };
}

// export fn EmbeddedLogoImage() c.BinaryData {
//     if (build_options.logo_file) |p| {
//         return embeddedFile(p);
//     } else {
//         return .{};
//     }
// }

extern "C" BinaryData EmbeddedLogoImage() {
#include "logo.hpp"
  return BinaryData{
      .data = plugin_gui_logo_png,
      .size = sizeof(plugin_gui_logo_png),
      .filename = MakeEmbeddedString("images/logo.png"),
  };
}

// export fn EmbeddedIconImage() c.BinaryData {
//     if (build_options.icon_file) |p| {
//         return embeddedFile(p);
//     } else {
//         return .{};
//     }
// }

extern "C" BinaryData EmbeddedIconImage() {
#include "icon.hpp"
  return BinaryData{
      .data = icon_background_256px_png,
      .size = sizeof(icon_background_256px_png),
      .filename = MakeEmbeddedString("images/icon.png"),
  };
}

// export fn EmbeddedAboutLibraryTemplateRtf() c.BinaryData {
//     return embeddedFile("about_library_template.rtf");
// }

extern "C" BinaryData EmbeddedAboutLibraryTemplateRtf() {
#include "about_library_template.hpp"
  return BinaryData{
      .data = about_library_template_rtf,
      .size = sizeof(about_library_template_rtf),
      .filename = MakeEmbeddedString("about_library_template.rtf"),
  };
}

// export fn EmbeddedPackageInstallationRtf() c.BinaryData {
//     return embeddedFile("package_installation.rtf");
// }

extern "C" BinaryData EmbeddedPackageInstallationRtf() {
#include "package_installation.hpp"
  return BinaryData{
      .data = package_installation_rtf,
      .size = sizeof(package_installation_rtf),
      .filename = MakeEmbeddedString("package_installation.rtf"),
  };
}

// const embedded_irs = [_]c.EmbeddedIr{
//     // Bizarre FX
//     .{
//         .data = embeddedFile("reverb_irs/bizarre_fx/cyber-pulse.flac"),
//         .name = embeddedString("Cyber Pulse"),
//         .folder = embeddedString("Bizarre FX"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/bizarre_fx/dropping-pitch.flac"),
//         .name = embeddedString("Dropping Pitch"),
//         .folder = embeddedString("Bizarre FX"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/bizarre_fx/flickering.flac"),
//         .name = embeddedString("Flickering"),
//         .folder = embeddedString("Bizarre FX"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/bizarre_fx/fm-flicker.flac"),
//         .name = embeddedString("FM Flicker"),
//         .folder = embeddedString("Bizarre FX"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/bizarre_fx/low-vibration.flac"),
//         .name = embeddedString("Low Vibration"),
//         .folder = embeddedString("Bizarre FX"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/bizarre_fx/passby.flac"),
//         .name = embeddedString("Passby"),
//         .folder = embeddedString("Bizarre FX"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/bizarre_fx/synth-didgeridoo.flac"),
//         .name = embeddedString("Synth Didgeridoo"),
//         .folder = embeddedString("Bizarre FX"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//
//
//     // Found Sounds
//     .{
//         .data = embeddedFile("reverb_irs/found_sounds/creaky-door.flac"),
//         .name = embeddedString("Creaky Door"),
//         .folder = embeddedString("Found Sounds"),
//         .tag1 = embeddedString("found sounds"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/found_sounds/crunch-1.flac"),
//         .name = embeddedString("Crunch 1"),
//         .folder = embeddedString("Found Sounds"),
//         .tag1 = embeddedString("found sounds"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/found_sounds/crunch-2.flac"),
//         .name = embeddedString("Crunch 2"),
//         .folder = embeddedString("Found Sounds"),
//         .tag1 = embeddedString("found sounds"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/found_sounds/rain.flac"),
//         .name = embeddedString("Rain"),
//         .folder = embeddedString("Found Sounds"),
//         .tag1 = embeddedString("found sounds"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/found_sounds/rattle.flac"),
//         .name = embeddedString("Rattle"),
//         .folder = embeddedString("Found Sounds"),
//         .tag1 = embeddedString("found sounds"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/found_sounds/water-walkoff.flac"),
//         .name = embeddedString("Water Walkoff"),
//         .folder = embeddedString("Found Sounds"),
//         .tag1 = embeddedString("found sounds"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/found_sounds/water.flac"),
//         .name = embeddedString("Water"),
//         .folder = embeddedString("Found Sounds"),
//         .tag1 = embeddedString("found sounds"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/found_sounds/wind.flac"),
//         .name = embeddedString("Wind"),
//         .folder = embeddedString("Found Sounds"),
//         .tag1 = embeddedString("found sounds"),
//         .tag2 = embeddedString("unusual"),
//         .description = embeddedString(""),
//     },
//
//
//     // Simulated Space
//     .{
//         .data =
//         embeddedFile("reverb_irs/simulated_space/chamber-like-1.flac"), .name
//         = embeddedString("Chamber-like 1"), .folder =
//         embeddedString("Simulated Space"), .tag1 =
//         embeddedString("synthesized"), .tag2 = embeddedString("chamber"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data =
//         embeddedFile("reverb_irs/simulated_space/chamber-like-2.flac"), .name
//         = embeddedString("Chamber-like 2"), .folder =
//         embeddedString("Simulated Space"), .tag1 =
//         embeddedString("synthesized"), .tag2 = embeddedString("chamber"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data =
//         embeddedFile("reverb_irs/simulated_space/chamber-like-3.flac"), .name
//         = embeddedString("Chamber-like 3"), .folder =
//         embeddedString("Simulated Space"), .tag1 =
//         embeddedString("synthesized"), .tag2 = embeddedString("chamber"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data =
//         embeddedFile("reverb_irs/simulated_space/cathedral-like-1.flac"),
//         .name = embeddedString("Cathedral-like 1"),
//         .folder = embeddedString("Simulated Space"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("cathedral"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data =
//         embeddedFile("reverb_irs/simulated_space/cathedral-like-2.flac"),
//         .name = embeddedString("Cathedral-like 2"),
//         .folder = embeddedString("Simulated Space"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("cathedral"),
//         .description = embeddedString(""),
//     },
//
//
//     // Smooth
//     .{
//         .data = embeddedFile("reverb_irs/smooth/airy.flac"),
//         .name = embeddedString("Airy"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/formant.flac"),
//         .name = embeddedString("Formant"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/lush-modulated-1.flac"),
//         .name = embeddedString("Lush Modulated 1"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/lush-modulated-2.flac"),
//         .name = embeddedString("Lush Modulated 2"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/lush-modulated-3.flac"),
//         .name = embeddedString("Lush Modulated 3"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/lush-tail.flac"),
//         .name = embeddedString("Lush Tail"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/rough-crackle.flac"),
//         .name = embeddedString("Rough Crackle"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/white-noise-1.flac"),
//         .name = embeddedString("White Noise 1"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/white-noise-2.flac"),
//         .name = embeddedString("White Noise 2"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/white-noise-3.flac"),
//         .name = embeddedString("White Noise 3"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/white-noise-4.flac"),
//         .name = embeddedString("White Noise 4"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/white-noise-5.flac"),
//         .name = embeddedString("White Noise 5"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//     .{
//         .data = embeddedFile("reverb_irs/smooth/white-noise-6.flac"),
//         .name = embeddedString("White Noise 6"),
//         .folder = embeddedString("Smooth"),
//         .tag1 = embeddedString("synthesized"),
//         .tag2 = embeddedString("smooth"),
//         .description = embeddedString(""),
//     },
//};

#define EMBEDDED_FILE(data_name, file_name)                                    \
  {                                                                            \
      .data = data_name,                                                       \
      .size = sizeof(data_name),                                               \
      .filename = MakeEmbeddedString(file_name),                               \
  }

#include "airy.hpp"
#include "cathedral_like_1.hpp"
#include "cathedral_like_2.hpp"
#include "chamber_like_1.hpp"
#include "chamber_like_2.hpp"
#include "chamber_like_3.hpp"
#include "creaky_door.hpp"
#include "crunch_1.hpp"
#include "crunch_2.hpp"
#include "cyber_pulse.hpp"
#include "dropping_pitch.hpp"
#include "flickering.hpp"
#include "fm_flicker.hpp"
#include "formant.hpp"
#include "low_vibration.hpp"
#include "lush_modulated_1.hpp"
#include "lush_modulated_2.hpp"
#include "lush_modulated_3.hpp"
#include "lush_tail.hpp"
#include "passby.hpp"
#include "rain.hpp"
#include "rattle.hpp"
#include "rough_crackle.hpp"
#include "synth_didgeridoo.hpp"
#include "water.hpp"
#include "water_walkoff.hpp"
#include "white_noise_1.hpp"
#include "white_noise_2.hpp"
#include "white_noise_3.hpp"
#include "white_noise_4.hpp"
#include "white_noise_5.hpp"
#include "white_noise_6.hpp"
#include "wind.hpp"

static const EmbeddedIr embedded_irs[] = {
    // Bizarre FX
    {
        .data = EMBEDDED_FILE(cyber_pulse_flac, "cyber-pulse.flac"),
        .name = MakeEmbeddedString("Cyber Pulse"),
        .folder = MakeEmbeddedString("Bizarre FX"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(dropping_pitch_flac, "dropping-pitch.flac"),
        .name = MakeEmbeddedString("Dropping Pitch"),
        .folder = MakeEmbeddedString("Bizarre FX"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(flickering_flac, "flickering.flac"),
        .name = MakeEmbeddedString("Flickering"),
        .folder = MakeEmbeddedString("Bizarre FX"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(fm_flicker_flac, "fm-flicker.flac"),
        .name = MakeEmbeddedString("FM Flicker"),
        .folder = MakeEmbeddedString("Bizarre FX"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(low_vibration_flac, "low-vibration.flac"),
        .name = MakeEmbeddedString("Low Vibration"),
        .folder = MakeEmbeddedString("Bizarre FX"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(passby_flac, "passby.flac"),
        .name = MakeEmbeddedString("Passby"),
        .folder = MakeEmbeddedString("Bizarre FX"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(synth_didgeridoo_flac, "synth-didgeridoo.flac"),
        .name = MakeEmbeddedString("Synth Didgeridoo"),
        .folder = MakeEmbeddedString("Bizarre FX"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },

    // Found Sounds
    {
        .data = EMBEDDED_FILE(creaky_door_flac, "creaky-door.flac"),
        .name = MakeEmbeddedString("Creaky Door"),
        .folder = MakeEmbeddedString("Found Sounds"),
        .tag1 = MakeEmbeddedString("found sounds"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(crunch_1_flac, "crunch-1.flac"),
        .name = MakeEmbeddedString("Crunch 1"),
        .folder = MakeEmbeddedString("Found Sounds"),
        .tag1 = MakeEmbeddedString("found sounds"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(crunch_2_flac, "crunch-2.flac"),
        .name = MakeEmbeddedString("Crunch 2"),
        .folder = MakeEmbeddedString("Found Sounds"),
        .tag1 = MakeEmbeddedString("found sounds"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(rain_flac, "rain.flac"),
        .name = MakeEmbeddedString("Rain"),
        .folder = MakeEmbeddedString("Found Sounds"),
        .tag1 = MakeEmbeddedString("found sounds"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(rattle_flac, "rattle.flac"),
        .name = MakeEmbeddedString("Rattle"),
        .folder = MakeEmbeddedString("Found Sounds"),
        .tag1 = MakeEmbeddedString("found sounds"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(water_walkoff_flac, "water-walkoff.flac"),
        .name = MakeEmbeddedString("Water Walkoff"),
        .folder = MakeEmbeddedString("Found Sounds"),
        .tag1 = MakeEmbeddedString("found sounds"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(water_flac, "water.flac"),
        .name = MakeEmbeddedString("Water"),
        .folder = MakeEmbeddedString("Found Sounds"),
        .tag1 = MakeEmbeddedString("found sounds"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(wind_flac, "wind.flac"),
        .name = MakeEmbeddedString("Wind"),
        .folder = MakeEmbeddedString("Found Sounds"),
        .tag1 = MakeEmbeddedString("found sounds"),
        .tag2 = MakeEmbeddedString("unusual"),
        .description = MakeEmbeddedString(""),
    },

    // Simulated Space
    {
        .data = EMBEDDED_FILE(chamber_like_1_flac, "chamber-like-1.flac"),
        .name = MakeEmbeddedString("Chamber-like 1"),
        .folder = MakeEmbeddedString("Simulated Space"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("chamber"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(chamber_like_2_flac, "chamber-like-2.flac"),
        .name = MakeEmbeddedString("Chamber-like 2"),
        .folder = MakeEmbeddedString("Simulated Space"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("chamber"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(chamber_like_3_flac, "chamber-like-3.flac"),
        .name = MakeEmbeddedString("Chamber-like 3"),
        .folder = MakeEmbeddedString("Simulated Space"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("chamber"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(cathedral_like_1_flac, "cathedral-like-1.flac"),
        .name = MakeEmbeddedString("Cathedral-like 1"),
        .folder = MakeEmbeddedString("Simulated Space"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("cathedral"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(cathedral_like_2_flac, "cathedral-like-2.flac"),
        .name = MakeEmbeddedString("Cathedral-like 2"),
        .folder = MakeEmbeddedString("Simulated Space"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("cathedral"),
        .description = MakeEmbeddedString(""),
    },

    // Smooth
    {
        .data = EMBEDDED_FILE(airy_flac, "airy.flac"),
        .name = MakeEmbeddedString("Airy"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(formant_flac, "formant.flac"),
        .name = MakeEmbeddedString("Formant"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(lush_modulated_1_flac, "lush-modulated-1.flac"),
        .name = MakeEmbeddedString("Lush Modulated 1"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(lush_modulated_2_flac, "lush-modulated-2.flac"),
        .name = MakeEmbeddedString("Lush Modulated 2"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(lush_modulated_3_flac, "lush-modulated-3.flac"),
        .name = MakeEmbeddedString("Lush Modulated 3"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(lush_tail_flac, "lush-tail.flac"),
        .name = MakeEmbeddedString("Lush Tail"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(rough_crackle_flac, "rough-crackle.flac"),
        .name = MakeEmbeddedString("Rough Crackle"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(white_noise_1_flac, "white-noise-1.flac"),
        .name = MakeEmbeddedString("White Noise 1"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(white_noise_2_flac, "white-noise-2.flac"),
        .name = MakeEmbeddedString("White Noise 2"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(white_noise_3_flac, "white-noise-3.flac"),
        .name = MakeEmbeddedString("White Noise 3"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(white_noise_4_flac, "white-noise-4.flac"),
        .name = MakeEmbeddedString("White Noise 4"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(white_noise_5_flac, "white-noise-5.flac"),
        .name = MakeEmbeddedString("White Noise 5"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
    {
        .data = EMBEDDED_FILE(white_noise_6_flac, "white-noise-6.flac"),
        .name = MakeEmbeddedString("White Noise 6"),
        .folder = MakeEmbeddedString("Smooth"),
        .tag1 = MakeEmbeddedString("synthesized"),
        .tag2 = MakeEmbeddedString("smooth"),
        .description = MakeEmbeddedString(""),
    },
};
//
// export fn GetEmbeddedIrs() c.EmbeddedIrs {
//     return .{
//         .irs = &embedded_irs,
//         .count = embedded_irs.len,
//     };
// }
//
//

extern "C" EmbeddedIrs GetEmbeddedIrs() {
  return EmbeddedIrs{
      .irs = embedded_irs,
      .count = sizeof(embedded_irs) / sizeof(embedded_irs[0]),
  };
}
