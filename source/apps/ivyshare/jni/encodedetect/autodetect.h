/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AUTODETECT_H
#define AUTODETECT_H

#include <inttypes.h>

// flags used for native encoding detection
enum {
    kEncodingNone               = 0,
    kEncodingShiftJIS           = (1 << 0),
    kEncodingGBK                = (1 << 1),
    kEncodingBig5               = (1 << 2),
    kEncodingEUCKR              = (1 << 3),

    kEncodingAll                = (kEncodingShiftJIS | kEncodingGBK | kEncodingBig5 | kEncodingEUCKR),
};


// returns a bitfield containing the possible native encodings for the given character
// extern uint32_t findPossibleEncodings(int ch);
extern uint32_t possibleEncodings(const char* s);



class CharacterEncoder
{
public:
    CharacterEncoder();
    ~CharacterEncoder();

public:
    static bool isUTF8(const char *str);

public:
    static bool is_ascii(const char *str);
    static bool is_non_ascii_UTF8(const char* str, int &len);
    static bool is_utf8_code(const char* str, int *wordcount);
    static bool is_gbk_code(const char* str, int *wordcount);
};

#endif // AUTODETECT_H
