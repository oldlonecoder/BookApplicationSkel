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

#include <BookApplicationSkel/ApplicationSkel.h>

#define src_location std::source_location::current()
#define out_fun     std::cout << src_location.function_name() << " :" <<


namespace Skel
{

class Application : public Book::ApplicationSkel
{
protected:
    Book::Result SetupAppBook();
public:
    Application(const std::string& BookName, int argc, char** argv);
    ~Application() override;

    Book::Result Run() override;
};


Application::Application(const std::string& BookName, int argc, char** argv): Book::ApplicationSkel(BookName, argc,argv)
{
}


Application::~Application()
{

}

Book::Result Application::Run()
{
    auto R = SetupAppBook();
    if (!R)
        return R;
    
    AppBook::Debug() << " The Setup process went well and there is the end of the tests for now " << Utf::Glyph::Happy2;
    return Book::Result::Ok;
}

Book::Result Application::SetupAppBook()
{

    out_fun " Calling parent class :\n";
    (void)Setup();
    // ...
    out_fun " Creating this test section:\n";
    AppBook::CreateSection("App").Open().CreateSectionContents("Output");

    AppBook()["App"]["Output"];

    AppBook::Debug() << " App: Section and contents Setup was Successful!";
    return Book::Result::Accepted;
}

}



auto main(int argc, char** argv) -> int
{
    Skel::Application App("SkelTest", argc,argv);
    return static_cast<int>(App.Run());

}

