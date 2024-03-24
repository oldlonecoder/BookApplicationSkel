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

#include "BookApplicationSkel/ApplicationSkel.h"
#include <csignal>


#define src_location std::source_location::current()
#define out_fun     std::cout << src_location.function_name() << " :" <<



void sig_int( int s )
{
    //rem::push_interrupted() << " dump messages stream and exit:";
    //rem::clear(nullptr);
    std::cerr << "\n---------------------------------------\n sig interrupt caugh - flushing Book contents.\n ";
    AppBook::Close();
    exit(3);
}

void sig_fault( int s)
{
    //rem::push_segfault() << " dump messages stream and exit:";
    //rem::clear(nullptr);
    std::cerr << " sigfault caught...\n";
    AppBook::Close();
    exit(127);
}

void sig_abort( int s)
{
    //rem::push_aborted() << " dump messages stream and exit:";
    //rem::clear(nullptr);
    std::cerr << s << '\n';
    AppBook::Close(); //< Safe close - Only closes once - Can be called multiple times
    exit(127);
}


namespace Book
{

ApplicationSkel* _APP{nullptr};

void ApplicationSkel::InstallSignals()
{
    std::signal(SIGINT, sig_int);
    std::signal(SIGSEGV, sig_fault);
    std::signal(SIGABRT, sig_abort);
}

ApplicationSkel::ApplicationSkel()
{
    if(_APP)
    {
        std::cerr << Color::Ansi(Color::Red4) << " Error: " << Color::Ansi(Color::Reset) << "Cannot re-instance Application class." << std::endl;
        exit(1);
    }
}


ApplicationSkel::~ApplicationSkel()
{
    mArgs.clear();
    auto R = AppBook::End();//< Safe End() : Alias to Close() - Only closes once - Can be called multiple times
    auto [I,P] = Book::Enums::CodeAttributes(R);
    StrAcc Str;
    Str << Color::White << '[' << Color::Chartreuse6 << I << ' ' << P << Book::Enums::CodeText(R) << Color::Reset << ']';

    out_fun " Return code from AppBook::End(): " << Str() << std::endl;
}

//Result ApplicationSkel::Run()
//{
//    throw AppBook::Exception()[AppBook::Fatal() << "Cannot be invoked from this base Application class!"];
//
//    return {};
//}

ApplicationSkel::ApplicationSkel(const std::string &AppName, int argc, char** argv) : Object(nullptr, AppName)
{
    _APP = this;
    out_fun " Begin AppBook: " << AppName << ":\n";
    (void)AppBook::Begin(AppName);
    //AppBook::Debug() << "Book '" << AppName << "' created...";

    if(argc)
    {
        for(int a=1; a<argc; a++) mArgs.emplace_back(argv[a]);
    }

}

Book::Result ApplicationSkel::Setup()
{
    // Systématique :
    Book::Select()["BookApi"]["Journal"];
    Book::Debug() << "\" Install signals:";
    ApplicationSkel::InstallSignals();
    Book::Debug() <<  " Creating section: " << "Skel :\n";
    auto& Sec = AppBook::CreateSection("Skel");

    Book::Debug() <<  " This section in Skel: '" << Sec.Id() << ":";
    Sec.Open();
    Sec.CreateSectionContents("Skel-Library.journal");
    Book::Select()["Skel"]["Skel-Library.journal"];

    Book::Debug() << " Application Skel library journal started...";
    return Result::Success;
}


}
