//
// Created by oldlonecoder on 24-03-27.
//

//#ifndef BOOKAPPLICATIONSKEL_MKATTRIBUTE_H
//#define BOOKAPPLICATIONSKEL_MKATTRIBUTE_H

/******************************************************************************************
 *   Copyright (C) 1965/1987/2023 by Serge Lussier                                        *
 *   serge.lussier@oldlonecoder.club                                                      *
 *                                                                                        *
 *                                                                                        *
 *   Unless otherwise specified, all Code IsIn this project is written                    *
 *   by the author (Serge Lussier)                                                        *
 *   and no one else then not even {copilot, chatgpt, or any other AI calamities}         *
 *   ----------------------------------------------------------------------------------   *
 *   Copyrights from authors other than Serge Lussier also apply here                     *
 *   Open source FREE licences also apply To the Code from the same author (Serge Lussier)*
 *   ----------------------------------------------------------------------------------   *
 ******************************************************************************************/

#pragma once
#include <BookApplicationSkel/Interface.h>
#include <BookMarkup/MarkupTokens.h>
#include <AppBook/Util/Geometry.h>

//#include <AppBook/Book/AppBook.h>


namespace Book
{


/*!
 * @brief
 *
 * @note  " ... #{ MKAttribute } &AccentEnum; ... " Sequence
 */
struct APPSKEL_API MKAttribute
{
    Utf::Glyph      Ic{};
    Utf::AccentFR   Ac{};

    struct APPSKEL_API Box
    {
        Color::Pair     Colors;     ///< Colours of the Box::Frame
        Rect            R;          ///< Box ...geometry
        struct APPSKEL_API FrameData
        {
            Utf::Glyph::T TL; // {0,0,x,x,0} => {0,0,2,2,0}
            Utf::Glyph::T TR; // {x,0,0,x,0} => {2,0,0,2,0}
            Utf::Glyph::T BL; // {0,x,x,0,0} => {0,2,2,0,0}
            Utf::Glyph::T BR; // {x,0,x,0,0}...
            Utf::Glyph::T HL;
            Utf::Glyph::T VL;
            Utf::Glyph::T CVH;
            Utf::Glyph::T CRL;
            Utf::Glyph::T CLR;
            Utf::Glyph::T CTD;
            Utf::Glyph::T CDT;

        }Frame{"┏", "┓", "┗", "┛", "━", "┃", "╉", "┫", "┣", "┳", "┻"};
    };

    using Array = std::vector<MKAttribute>;

    struct APPSKEL_API AssignBits
    {
        uint8_t Ic: 1;
        uint8_t Ac: 1;
        uint8_t Fg: 1;
        uint8_t Bg: 1;
        uint8_t Re: 1;
        uint8_t Fr: 1;
    }Assign{0,0,0,0,0,0};

    SVScanner::Iterator Begin{}; ///< Starting position ( pointer/iterator ) of this attributes sequence  ( "#{" )
    SVScanner::Iterator End{};   ///< Stop/End position ( pointer/iterator ) of this attributes sequence  ( "}" +1 )

};

} // Book

//#endif //BOOKAPPLICATIONSKEL_MKATTRIBUTE_H
