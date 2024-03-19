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
#include <AppBook/Util/Object.h>


namespace Book
{

class APPSKEL_API ApplicationSkel : public Util::Object
{

    static void InstallSignals();
    ApplicationSkel();

    StrAcc::CArray mArgs;
protected:
    virtual Book::Result Setup(); ///< Call first from the derived::Setup(), then continue the Setting up...

public:
    ApplicationSkel(const std::string& AppName, int argc=0, char** argv=nullptr);
    ~ApplicationSkel() override;

    ;

};

}


