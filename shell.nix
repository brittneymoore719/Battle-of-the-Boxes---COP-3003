# nixOS specific, you can ignore this file if you are on other platforms

{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    cmake
    pkg-config
  ];

  # provides sfml linux build requirements
  buildInputs = with pkgs; [
    libxrandr
    libxcursor
    libxi
    libGLU
    udev
    freetype
    libvorbis
    flac
  ];
}
