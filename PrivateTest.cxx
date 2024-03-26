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
#include <BookMarkup/MarkupTokens.h>
#include <Lexer/Lexer.h>




namespace Skel
{

class Application : public Book::ApplicationSkel
{
protected:
    Book::Result Setup() override;
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
    auto R = Setup();
    if (!R)
        return R;
    
    Book::Debug() << " The Setup process went well..." << Utf::Glyph::Happy2;
    Book::Debug() << " Now Begin testing the lexer ...";

    //Book::MarkupTokens MarkupLang;
    Book::MarkupTokens TT;
    lex::Lexer Lex;
    Lex.Config() = {
        R"(
      Hello, Word! -> Here is the #{Fg:Yellow} Markup Test! #{/}
)",
        &TT
    };


    return Lex();

    try {
        Book::Status() << " All is ok, test ok, Application ok! Bye!";
    }
    catch(AppBook::Exception& E)
    {
        Book::Except() << " What:" << E.what();
    }
    catch(std::exception& E)
    {
        Book::Except() << " What:" << E.what();
    }
    catch(const char* E)
    {
        Book::Except() << E;
    }

    //AppBook::Close();

    return Book::Result::Ok;
}

Book::Result Application::Setup()
{

    Book::Debug() << " Calling parent class :\n";
    (void) ApplicationSkel::Setup();
    // ...
    Book::Debug() << " Creating this test section:\n";
    AppBook::CreateSection("App").Open().CreateSectionContents("Output");

    Book::Select()["App"]["Output"];

    Book::Debug() << " App: Section and contents Setup was Successful";

    return Book::Result::Accepted;
}

}



auto main(int argc, char** argv) -> int
{
    Skel::Application App("SkelTest", argc,argv);
    return static_cast<int>(App.Run());
}

