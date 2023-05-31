// ignore_for_file: overridden_fields, annotate_overrides

import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:shared_preferences/shared_preferences.dart';

const kThemeModeKey = '__theme_mode__';
SharedPreferences? _prefs;

abstract class FlutterFlowTheme {
  static Future initialize() async =>
      _prefs = await SharedPreferences.getInstance();
  static ThemeMode get themeMode {
    final darkMode = _prefs?.getBool(kThemeModeKey);
    return darkMode == null
        ? ThemeMode.system
        : darkMode
            ? ThemeMode.dark
            : ThemeMode.light;
  }

  static void saveThemeMode(ThemeMode mode) => mode == ThemeMode.system
      ? _prefs?.remove(kThemeModeKey)
      : _prefs?.setBool(kThemeModeKey, mode == ThemeMode.dark);

  static FlutterFlowTheme of(BuildContext context) =>
      Theme.of(context).brightness == Brightness.dark
          ? DarkModeTheme()
          : LightModeTheme();

  // Color primaryColor;
  // Color secondaryColor;
  // Color tertiaryColor;
  // Color alternate;
  // Color primaryBackground;
  // Color secondaryBackground;
  // Color primaryText;
  // Color secondaryText;
  Color primaryColor = const Color(0xFF4B39EF);
  Color secondaryColor = const Color(0xFF39D2C0);
  Color tertiaryColor = const Color(0xFFEE8B60);
  Color alternate = const Color(0xFFFF5963);
  Color primaryBackground = const Color(0xFFFFFFFF);
  Color secondaryBackground = const Color(0xFFF1F4F8);
  Color primaryText = Color.fromARGB(255, 172, 38, 38);
  Color secondaryText = Color.fromARGB(255, 150, 39, 39);
  Color buttonColor = Color.fromARGB(255, 172, 38, 38);

  TextStyle get title1 => GoogleFonts.getFont(
        'Poppins',
        color: primaryText,
        fontWeight: FontWeight.w600,
        fontSize: 24,
      );
  TextStyle get title2 => GoogleFonts.getFont(
        'Poppins',
        color: secondaryText,
        fontWeight: FontWeight.w600,
        fontSize: 22,
      );
  TextStyle get title3 => GoogleFonts.getFont(
        'Poppins',
        color: primaryText,
        fontWeight: FontWeight.w600,
        fontSize: 20,
      );
  TextStyle get subtitle1 => GoogleFonts.getFont(
        'Poppins',
        color: primaryText,
        fontWeight: FontWeight.w600,
        fontSize: 18,
      );
  TextStyle get subtitle2 => GoogleFonts.getFont(
        'Poppins',
        color: secondaryText,
        fontWeight: FontWeight.w600,
        fontSize: 16,
      );
  TextStyle get bodyText1 => GoogleFonts.getFont(
        'Poppins',
        color: primaryText,
        fontWeight: FontWeight.w600,
        fontSize: 14,
      );
  TextStyle get bodyText2 => GoogleFonts.getFont(
        'Poppins',
        color: secondaryText,
        fontWeight: FontWeight.w600,
        fontSize: 14,
      );
}

class LightModeTheme extends FlutterFlowTheme {
  Color primaryColor = const Color(0xFF1B1B1B);
  Color secondaryColor = const Color(0xFF39D2C0);
  Color tertiaryColor = const Color(0xFFEE8B60);
  Color alternate = Color.fromARGB(255, 85, 85, 85);
  Color primaryBackground = Color(0xFFFFFFFF);
  Color secondaryBackground = Color.fromARGB(255, 228, 230, 233);
  Color primaryText = Color.fromARGB(255, 0, 0, 0);
  Color secondaryText = Color.fromARGB(255, 49, 145, 219);
  Color buttonColor = Color.fromARGB(255, 172, 38, 38);
}

class DarkModeTheme extends FlutterFlowTheme {
  Color primaryColor = const Color(0xFF4B39EF);
  Color secondaryColor = const Color(0xFF39D2C0);
  Color tertiaryColor = const Color(0xFFEE8B60);
  Color alternate = Color.fromARGB(255, 255, 255, 255);
  Color primaryBackground = const Color(0xFF091249);
  Color secondaryBackground = Color.fromARGB(255, 5, 11, 47);
  Color primaryText = Color.fromARGB(255, 255, 255, 255);
  Color secondaryText = Color.fromARGB(255, 48, 140, 226);
  Color buttonColor = Color.fromARGB(255, 172, 38, 38);
}

extension TextStyleHelper on TextStyle {
  TextStyle override({
    String fontFamily = "RaleWay",
    Color? color,
    double? fontSize,
    FontWeight? fontWeight,
    FontStyle? fontStyle,
    bool useGoogleFonts = true,
    double? lineHeight,
  }) =>
      useGoogleFonts
          ? GoogleFonts.getFont(
              fontFamily,
              color: color ?? this.color,
              fontSize: fontSize ?? this.fontSize,
              fontWeight: fontWeight ?? this.fontWeight,
              fontStyle: fontStyle ?? this.fontStyle,
              height: lineHeight,
            )
          : copyWith(
              fontFamily: fontFamily,
              color: color,
              fontSize: fontSize,
              fontWeight: fontWeight,
              fontStyle: fontStyle,
              height: lineHeight,
            );
}
