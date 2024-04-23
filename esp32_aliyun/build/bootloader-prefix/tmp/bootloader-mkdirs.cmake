# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/software/Espressif/frameworks/esp-idf-v4.4.6/components/bootloader/subproject"
  "C:/Users/11989/Desktop/project_new/sample_project/build/bootloader"
  "C:/Users/11989/Desktop/project_new/sample_project/build/bootloader-prefix"
  "C:/Users/11989/Desktop/project_new/sample_project/build/bootloader-prefix/tmp"
  "C:/Users/11989/Desktop/project_new/sample_project/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/11989/Desktop/project_new/sample_project/build/bootloader-prefix/src"
  "C:/Users/11989/Desktop/project_new/sample_project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/11989/Desktop/project_new/sample_project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
